#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int d[n+1];
    for (int k = n; k>=1;k--){
        memset(d,0,sizeof(d));
        int pre = 0;
        for (int i=0;i<=n-k;i++) {
            int x = s[i] - '0';
            pre = (pre + d[i]) % 2;
            int now = (x + pre) % 2;
            if (now == 0) {
                d[i+1] = (d[i+1] + 1) % 2;
                d[i+k] = (d[i+k] + 1) % 2;
            }
        }
        bool res = true;
        for (int i=n-k+1;i<n;i++) {
            pre = (pre + d[i]) % 2;
            int now = (s[i] - '0' + pre) % 2;
            if (now == 0) {
                res = false;
                break;
            }
        }
        if (res) {
            cout<<k<<endl;
            return;
        }
    }
}

signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}