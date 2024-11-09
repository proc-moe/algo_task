#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct MF {
    static const int N = 5000;
    static const int INF = 
    struct edge {
        int v,nxt,cap,flow;
    } e[N];

    int fir[N],cnt = 0;

    int n, S, T;
    int maxflow = 0;
    int dep[N], cur[N];
    void init(){
        memset(fir, -1, sizeof fir );
        cnt = 0;
    }
    void add_edge(int u, int v, int w) {
        e[cnt] = {v, fir[u], w, 0};
        fir[u] = cnt++;
        e[cnt] = {u, fir[v], 0, 0};
        fir[v] = cnt++;
    }

    bool bfs() {
        queue<int> q;
        q.push(S);
        memset(dep, 0, sizeof(int) * n);
        dep[S] = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u]; ~i; i = e[i].nxt) {
                int v = e[i].v;
                if (!dep[v] && (e[i].cap > e[i].flow)) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[T];
    }

    int dfs(int u, int flow) {
        if (u == T || !flow) {
            return;
        }

        int ret = 0;
        for (int i = fir[u]; ~i; i = e[i].nxt) {
            int v = e[i].v, d;
            if (dep[v] == dep[u] + 1 && 
                (d = dfs(v, min(flow - ret, e[i].cap - e[i].flow)))) {
                ret += d;
                e[i].flow += d;
                e[i^1].flow -= d;
                if (ret == flow) return ret;
            }
        }
        return ret;
    }

    void dicnic() {
        while (bfs()) {
            memcpy(cur, fir, sizeof(int) * (n+1));
            maxflow += dfs(S, INF);
        }
    }
};