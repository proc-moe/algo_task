#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin>>n;
    int a[n];
    memset(a,0,sizeof(a));
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int c[n+1];
    memset(c,0,sizeof(c));
    for (int i=0;i<n;i++){
        c[a[i]]++;
    }
    int ans = 0;
    int used_1 = 0;
    for (int i=0;i<=n;i++){
        ans = i;
        if (c[i] == 0){
            break;
        }
        if (c[i] == 1){
            if (used_1 == 1) {
                break;
            }
            used_1 = 1;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}