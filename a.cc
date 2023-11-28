#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
struct Node {
    int id, v;
    bool operator < (const Node &y){
        return v < y.v;
    }
};
void solve() {
    priority_queue<Node> pq;
    int n,k;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pq.push(Node{i,a[i]});
    }
    int rightest_now = 0;
    int ans = 0;
    while (!pq.empty()){
        Node x = pq.top();
        pq.pop();
        int v = x.v;
        int id = x.id;
        if (id < rightest_now) {
            continue;
        } else {
            for (int i = rightest_now+1; i <= id; i++){
                
            }
        }

    }
    
}

int main(){
    int T;
    cin>>T;
    while (T--) solve();
}
