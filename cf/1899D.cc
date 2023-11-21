#include <bits/stdc++.h>
using namespace std;
#define int long long
map<pair<int,int>,int> mp;
void solve(){
    mp.clear();
    int n;
    cin>>n;
    int ans = 0;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        int t = 0;
        int p = x;
        while (p%2==0){
            t+=1;
            p/=2;
        }
        pair<int,int> pa;
        pa.first = x-t;
        pa.second = p;
        ans += mp[pa];
        mp[pa] += 1;
    }
    cout << ans <<endl;
}
signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}