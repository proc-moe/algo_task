#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 100;
struct Edge {
    int next, to;
}e[MAXN];
int head[MAXN];
int vis[MAXN];
int ans[MAXN];
void add(Edge e[], int& tot, int u, int v) {
    e[tot] = {head[u], v};
    head[u] = tot++;
}
int now = 0;
void dfs(int u, int from) {
    if (vis[u]) return;
    vis[u] = 1;
    if (now - from >= 4) {
        if ((now - from) % 2) {
            now += 1; 
        }
    } else if (now - from > 1) {
        now = from + 4;
    }
    ans[u] = now++;
    for (int i=head[u]; ~i; i = e[i].next) {
        dfs(e[i].to, ans[u]);
    }
}

void solve() {
    int n;
    cin >> n;
    int tot = 0;
    now = 1;
    for (int i=0; i<=n; i++) head[i] = -1;
    for (int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        add(e,tot, u,v);
        add(e, tot, v, u);
    }
    for (int i=0; i<=n; i++) vis[i] = 0;
    dfs(1, 0);
    for (int i=1;i<=n;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}