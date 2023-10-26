#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;

vector <long long> a;
int vis[N];
int son_count[N];
int cost[N];
int ans[N];
vector<vector<int>> e;
void dfs(int u){
    vis[u] = 1;
    son_count[u] = 1;
    int cost_of_self = 0;
    for (auto v: e[u]) {
        if (vis[v] == 0) {
            dfs(v);
            son_count[u] += son_count[v];
            cost[u] += cost[v];
            cost_of_self += (a[v] ^ a[u]) * son_count[v];
            cost[u] += cost[v];
        }
    }
}

void change_root(int u, int fa){
    int old_son_count_fa = son_count[fa];
    int old_son_count_u = son_count[u];
    int old_cost_fa = cost[fa];
    int old_cost_u = cost[u];
    if (fa != 0) {
        int new_son_count_fa = son_count[fa] - son_count[u];
        int new_son_count_u = son_count[u] + new_son_count_fa;
        int new_cost_fa = cost[fa] - (a[fa] ^ a[u]) * son_count[u];
        int new_cost_u = cost[u] + (a[fa] ^ a[u]) * new_son_count_fa;
        son_count[fa] = new_son_count_fa;
        son_count[u] = new_son_count_u;
        cost[fa] = new_cost_fa;
        cost[u] = new_cost_u;
        ans[u] = u;
    }
    for (auto &v: e[u]){
        if (vis[v]) continue;
        change_root(v,u);
    }
    if (fa != 0) {
        son_count[fa] = old_son_count_fa;
        son_count[u] = old_son_count_u;
        cost[fa] = old_cost_fa;
        cost[u] = old_cost_u;
    }
}
void solve(){
    int n;
    cin>>n;
    a.resize(n);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) e[i].clear();
    for (int i=1;i<=n;i++) vis[i] = 0;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    for (int i=1;i<=n;i++) vis[i] = 0;
    ans[1] = cost[1];
    change_root(1,0);
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

int main(){
    int T;
    cin>>T;
    while (T--){
        solve();
    }
}