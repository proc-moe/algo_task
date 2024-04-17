#include <bits/stdc++.h>
#include <cstring>
#include <utility>
#define int long long
using namespace std;
const int N = 55;
const int R = 14;
vector<vector<int>> v;
vector<pair<int,int>> loc;
vector<int> p;

int p3[R];

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    
    int dp[(1<<14)];
    int dp_bef[(1<<14)];
    memset(dp_bef,0,sizeof(dp_bef));
    memset(dp,0,sizeof(dp));
    int ans = 0;
    vector<pair<int,int>> v;
    for (int i=1;i<=n;i++) {
        string s; cin>>s;
        for (int j=1;j<=m;j++) if (s[j-1] == '#') v.push_back({i,j});
    }
    while (k--) {
        int x,y,pp;
        cin>>x>>y>>pp;
        
        for (int r=1;r<14;r++){
            int revenue = -p3[r];
            for (auto [a,b]: v) if ((a-x) * (a-x) + (b-y) * (b-y) <= r*r) revenue += pp; 
            if (revenue <= 0) continue;
            for (int j=1; j<(1<<14); j++) if (j & (1<<r)) dp[j] = max(dp[j], dp_bef[j ^ (1<<r)] + revenue);
        }
        memcpy(dp_bef, dp, sizeof(dp));
    }
    for (int i=0;i<(1<<14);i++) {
        ans = max(ans, dp_bef[i]);
    }
    cout<<ans<<endl;
}

signed main(){
    for (int i=0;i<R;i++) if (i==0) p3[i] = 1; else p3[i] = p3[i-1] * 3;
    int T;
    cin>>T;
    v.resize(N);
    for (int i=0;i<N;i++)  v[i].resize(N);
    while (T--) solve();
}