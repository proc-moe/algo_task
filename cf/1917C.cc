#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;

void solve(){
    int n,k,d;
    cin>>n>>k>>d;
    int a[n+1];
    int v[k+1];
    int require[n+1];
    int nxt_not_bigger_than_0[n+1];
    int rev[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) cin>>v[i];
    int harvest_at = -1;
    for (int i=1;i<=n;i++) {
        require[i] = a[i] - i;
    }
    int neg_pos_on_the_right = -1;
    for (int i=n;i>=0;i--) {
        nxt_not_bigger_than_0[i] = neg_pos_on_the_right;
        if (require[i] <= 0) {
            neg_pos_on_the_right = i;
        }
    }
    int i = 0;
    while (i != -1){
        int nxt = nxt_not_bigger_than_0[i];
        rev[nxt] = i;
        i = nxt_not_bigger_than_0[i];
    }

    int require_0 = 0;
    for (int i=1;i<=n;i++) {
        require_0 = require_0 + (require[i] == 0);
    }
    int max_score = -1;
    for (int i=1;i<=min(10*k,d);i++){
        max_score = max(max_score, require_0 + (d-i) / 2);
        int j = nxt_not_bigger_than_0[0];
        while (j != -1 && j <= v[k]){
            require[j] = require[j] + 1;
            if (require[j] > 0){
                require_0 -= 1;
                nxt_not_bigger_than_0[rev[j]] = nxt_not_bigger_than_0[j];
                rev[nxt_not_bigger_than_0[j]] = rev[j];
            }
            if (require[j] == 0) {
                require_0 += 1;
            }
            j = nxt_not_bigger_than_0[j];
        }
    }
    cout<<max_score<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while (T--) solve();
}