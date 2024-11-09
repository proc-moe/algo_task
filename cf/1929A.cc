#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int x,minn,maxx;
    minn = 1e9+1;
    maxx = -1;
    for (int i=1;i<=n;i++){
        cin>>x;
        minn = min(x,minn);
        maxx = max(x,maxx);
    }
    cout<<maxx - minn<<endl;
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}