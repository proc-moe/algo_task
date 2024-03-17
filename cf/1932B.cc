#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    int n;
    cin>>n;
    int a[n];
    memset(a,0,sizeof(a));
    for (int i=0;i<n;i++) cin>>a[i];
    int year = a[0];
    for (int i=1;i<n;i++) {
        year = a[i] * (year / a[i] + 1);
    }
    cout<<year<<endl;
}
signed main() {
    int T;
    cin>>T;
    while (T--) solve();
}