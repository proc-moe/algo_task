#include <bits/stdc++.h>
#define int long long
using namespace std;

int cal_s(int n){
    int s = 0;
    int now = 1;
    for (int i=1;i<=n;i++){
        s += i * now;
        now += 2;
    }
    return s;
}
void solve(){
    int n;
    cin>>n;
    int remain = 0;
    int l = 0;
    int r = n-1;
    if (n == 1) {
        cout<<"1 1"<<endl;
        cout<<"1 1 1"<<endl;
        return;
    }
    int s = cal_s(n);
    cout<<s<<" "<<2 * n<<endl;
    vector<int> a;
    for (int i=1;i<=n;i++){
        a.push_back(i);
    }
    for (int i=0;i<2*n;i++) {
        if (i % 2 == 0) cout<<1<<" "; else cout<<2<<" ";
        int id = (i / 2) + 1;
        cout<<id<<" ";
        int now = l;
        while (1) {
            cout<<a[now]<<" ";
            now = now + 1;
            if (now >= n) now = 0;
            if (r == now) {
                cout<<a[now]<<" "; 
                break;
            }
        }
        cout<<endl;

        if (remain == 0) {
            remain = 1;
            r -= 1;
            l -= 1;
            if (l<0) l = n-1;
            if (r<0) r = n-1;
        } else {
            remain = 0;
        }
    }
    
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
}