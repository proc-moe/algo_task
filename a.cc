#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <queue>
#define int long long
using namespace std;

int get_min(int x, vector<int> &a, vector<int> &b, int n,  int L) {
    if (x == 1) {
        return *min_element(a.begin()+1, a.begin()+1+n) <= L;
    }

    int res = LONG_LONG_MAX;
    for (int i = 1; i<=n;i++){
        int to_add = 0;
        int maxx_to_add = LONG_LONG_MAX;
        priority_queue<int> pq;
        for (int j=i+1;j<=i+x-2;j++){
            pq.push(a[j]);
            to_add += a[j];
        }
        maxx_to_add = to_add;
        res = min(res, maxx_to_add + a[i] + a[x+i-1] + (b[x+i-1] - b[i]));
        for (int l=x+1;l+i-1<=n;l++){
            int j=i+l-1;
            if (!pq.empty()) {
                int top = pq.top();
                if (a[j-1] < pq.top()) {
                    pq.pop();
                    pq.push(a[j]);
                    to_add = to_add - top + a[j];
                }
            }
            maxx_to_add = min(maxx_to_add, to_add);
            res = min(res, maxx_to_add + a[i] + a[j] + (b[j] - b[i]));
        }
    }
    return res <= L;
}
void solve() {
    int n,L;
    cin>>n>>L;
    vector<int> a(n+1),b(n+1);
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }

    int l,r;
    l = 1; r = n;
    int ans = -1;
    while (l<=r){
        int mid = (l+r)/2;
        /// Test mid
        get_min(mid,a,b,n, L);
    }
}

signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}
