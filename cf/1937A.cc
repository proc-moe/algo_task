#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin>>n;
    int t = 1;
    while (n != 1){
        n /= 2;
        t *= 2;
    }
    cout<<t<<endl;
}

signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}