#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;
    cout<<"? "<<1<<" "<<1<<endl;
    int l1;
    cin>>l1;
    cout<<"? "<<n<<" "<<1<<endl;
    int l2;
    cin>>l2;
    cout<<"? "<<n<<" "<<m<<endl;
    int l3;
    cin>>l3;
    int c = (l1+l2+3-n)/2;
    int r = l1+2-c;
    if (r <= 0 || r > n || c <= 0 || c > m) {
        int c = (l2 + 1 + m - l3) / 2;
        int r = n + m - l3 - c;
        cout<<"! "<<r<<" "<<c<<endl;
        return;
    }
    cout<<"? "<<r<<" "<<c<<endl;
    int ans;
    cin>>ans;
    if (ans == 0){
        cout<<"! "<<r<<" "<<c<<endl;
    } else {
        int c = (l2 + 1 + m - l3) / 2;
        int r = n + m - l3 - c;
        cout<<"! "<<r<<" "<<c<<endl;
    }
}

signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}