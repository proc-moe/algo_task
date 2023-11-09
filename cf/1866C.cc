#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DurablePermOfNode {
    int zeros, ones, invs;
};
typedef int Weight;
map<int, vector<pair<int, int>>> m;



const int N = 2e5+100;
bool vis[N];
DurablePermOfNode record[N];
void dfs(int u){
    if (vis[u] == 1){
        return;
    }
    vis[u] = 1;
    for (auto p: m[u]){
        int to = p.first;
        int weight = p.second;
        if (weight == 0) {
            record[u].invs = (record[u].invs + record[u].ones) % 998244353;
            record[u].zeros += 1;
            record[u].zeros %= 998244353;
        } else {
            record[u].ones += 1;
            record[u].ones %= 998244353;
        }
        dfs(to);
        record[u].invs = (record[u].invs + record[to].invs) % 998244353;
        record[u].invs = (record[u].invs + ((record[u].ones * record[to].zeros) % 998244353)) % 998244353;
        record[u].ones = (record[u].ones + record[to].ones) % 998244353;
        record[u].zeros = (record[u].zeros + record[to].zeros) % 998244353;
    }
}


void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        vector<pair<int,int>> node_info;
        node_info.clear();
        int tail_count;
        cin>>tail_count;
        for (int j=0; j<tail_count; j++){
            pair<int,int> data;
            cin>>data.first>>data.second;
            node_info.push_back(data);
        }
        m[i] = node_info;
    }
    dfs(1);
    cout<<record[1].invs<<endl;
}

signed main(){
    solve();
}