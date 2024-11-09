#include <bits/stdc++.h>
using namespace std;
void solve(){
    int x,k,a;
    cin>>k>>x>>a;
    if (a>x && (a-x)*k-x>0) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}