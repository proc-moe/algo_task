#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    cout << n / (min(x,y)) + (n % (min(x,y)) != 0) << endl;
}
int main(){
    int T;
    cin >> T;
    while (T--) solve();
}