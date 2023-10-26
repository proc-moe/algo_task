#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int n;
    vector<int> a;
    cin>>n;
    a.resize(n+2);
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<int> dp[2];
    dp[0].resize(n+2); dp[1].resize(n+2);

    for (int i=n;i>=1;i--){
        int v = a[i];
        dp[1][i] = max(v + dp[1][i+1], max(v + dp[0][i+1], dp[0][i+1]));
        dp[0][i] = max(dp[0][i+1], dp[1][i+1]);
    }
    cout<<dp[1][1]<<endl;
    
}
int32_t main(){
    cin>>T;
    while (T--) {
        solve();
    }
}