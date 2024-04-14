#include <bits/stdc++.h>
#define int long long
using namespace std;
 
void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    a.clear();
    int ans = 0;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]+=1;
        if (a[x] == 2) {
            ans += 1;
        }
    }
    cout<<ans<<endl;
    
}
 
signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}