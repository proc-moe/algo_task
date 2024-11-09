#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    int sum = 0;
    for (int i=0;i<n-2;i++) {
        sum += a[i];
    }
    sum -= a[n-2];
    sum += a[n-1];
    cout << sum << endl;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}