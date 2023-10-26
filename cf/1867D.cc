#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int to[N];
int v[N];
int maxx = 0;
void dfs(int now, int depth) {
    depth += 1;
    if (v[now]) {
        maxx = max(maxx, depth - v[now]);
        return;
    }
    v[now] = depth;
    dfs(to[now],depth);
}
void solve(){
    int n,k;
    cin>>n>>k;
    maxx = 0;
    for (int i=1;i<=n;i++){ 
        cin>>to[i];
        v[i] = 0;
    }
    for (int i=1;i<=n;i++){
        if (v[i] == 0) {
            dfs(i,0);
        }
    }
    if (maxx >= k){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
int main(){
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}