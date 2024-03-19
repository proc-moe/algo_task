#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#define int long long
using namespace std;
struct IdedVal{
    int id,a,b;
    bool operator < (const IdedVal &rhs) const {
        if (b == rhs.b) {
            return id < rhs.id;
        }
        return b < rhs.b;
    }
};

void solve2(IdedVal a[], int n,  int m) {
    int ans=0;
    for(int i=1;i<=n;i++){
        int res=0;
        priority_queue<int>q;
        for(int j=i;j<=n;j++){
            q.push(a[j].a);
            res+=a[j].a;
            while(!q.empty()&&res+(a[j].b-a[i].b)>m){
                res-=q.top();q.pop();
            }
            ans=max(ans,(int)q.size());
        }
    }
    cout<<ans<<endl;
}
void solve() {
    int n,L;
    cin>>n>>L;
    IdedVal  a[n+1];
    for (int i=1;i<=n;i++){
        int aa,bb;
        cin>>aa>>bb;
        a[i] = IdedVal {i, aa, bb};
    }
    sort(a+1,a+1+n);
    solve2(a, n, L);
}

signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}
