#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[300000];
ll pre[300000];
void solve(){
    ll x,n,k;
    cin>>n>>k>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i];
    ll maxx = -1e9;
    for (int p=0;p<=k;p++) {
        ll add_l = 1;
        ll add_r = n-p-x;
        ll sub_l = n-p-x+1;
        ll sub_r = n-p;
        ll add = 0;
        if (add_r < 1) {
            add = 0;
        } else {
            add = pre[add_r] - pre[add_l - 1];
        }

        if (sub_l < 1) {
            sub_l = 1;
        }
        if (sub_r < 1) {
            sub_r = 0;
        }
        ll sub = 0;
        if (sub_r == 0) {
            sub = 0;
        } else {
            sub = pre[sub_r] - pre[sub_l - 1];
        }
        maxx = max(maxx,add - sub);
    }
    cout<<maxx<<endl;    
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}