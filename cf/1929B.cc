#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int x,k,a;
    cin>>k>>x>>a;
    int cost[x+1];
    memset(cost,sizeof(cost),0);
    cost[1] = 1;
    for (int i=2;i<=x;i++){
        int cost_this = cost[i-1] / (k-1) + 1;
        double upper_than = cost[i-1] / double(k-1);
        int cost_this2 = ceil(upper_than + 1e-18);
        cost[i] = cost_this + cost[i-1];
        if (cost[i] > a) {
            cout<<"NO\n";
            return;
        }
    }
    
    if ( (a-cost[x])*k > a) cout<<"YES\n"; else cout<<"NO\n";
}
signed main(){
    int T;
    cin>>T;

    while (T--) solve();
}