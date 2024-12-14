#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[21];
    memset(a,0,sizeof(a));
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        a[x] += 1;
    }
    int res = 0;
    for (int i=0;i<=20;i++) {
        res += a[i] / 2;
    }
    cout << res << endl;

}
int main(){
    int T;
    cin >> T;
    while (T--) solve();
}