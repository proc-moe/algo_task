#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200;
int dp[N];
void solve() {
    int n;
    cin>>n;
    if (n<=60) cout<<dp[n]<<endl; else {
    int l = (n-1) / 30;
    int to_add = (l-1) * 2;
    int pos = n % 30;
    if (pos == 0) pos = 30;
    int another = dp[pos+30];
    cout<< to_add + another<<endl;
    }
}

signed main(){
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for (int i=1;i<N;i++){
        dp[i] = min(dp[i-1]+1,dp[i]);
        if (i>=3) dp[i] = min(dp[i-3] + 1, dp[i]);
        if (i>=6) dp[i] = min(dp[i-6] + 1, dp[i]);
        if (i>=10) dp[i] = min(dp[i-10] + 1, dp[i]);
        if (i>=15) dp[i] = min(dp[i-15] + 1, dp[i]);
    }
    int T;
    cin>>T;
    while (T--) solve();
}