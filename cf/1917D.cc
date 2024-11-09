#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int MOD = 998244353;

/// merge_sort, return `reversed count`.
int merge_sort(int x[], int l, int r) {
    int mid = (l+r) / 2;
    int lp = l;
    int rp = mid;
    int tmp[l-r];
    
    for (int i=0;i<l-r;i++) tmp[i] = 0;
    int now = 0;
    int c = merge_sort(x, l, mid) + merge_sort(x, mid, r);
    while (lp < mid && rp < r) {
        if (lp < mid && rp == r) {
            c += (r - mid);
            tmp[now] = x[lp];
            lp += 1; now++;
        }

        if (lp == mid && rp < r) {
            tmp[now] = x[rp];
            rp += 1; now++;
        }

        if (x[lp] > x[rp]) {
            c += (rp - mid);
            tmp[now] = x[lp];
            lp += 1; now++;
        } else if (x[lp] == x[rp]) {
            c += (rp - mid);
            tmp[now] = x[lp];
            lp += 1; now++;
        } else if (x[lp] < x[rp]) {
            tmp[now] = x[rp];
            rp += 1; now++;
        }
    }
    for (int i=l;i<r;i++) {
        x[i] = tmp[i-l];
    }
    return c;
}

int solve_n(int p[]) {
    
}
void solve() {
    int n,k;
    cin>>n>>k;
    int p[n],q[k];
    for (int i=0;i<n;i++) cin>>p[i];
    for (int i=0;i<k;i++) cin>>q[i];
    int n_reversed_in_q = merge_sort(q,0,k);

    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while (T--) solve();
}