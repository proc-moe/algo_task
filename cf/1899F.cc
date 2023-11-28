#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
int a[N];
void solve() {
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=q;i++){
        cin>>a[i];
    }
    for (int i=1;i<n;i++){
        cout<<i<<" "<<i+1<<endl;
    }
    int last_ans = n-1;
    int last_u = 2;
    for (int i=1;i<=q;i++){
        if (a[i] == last_ans) {
            cout<<"-1 -1 -1"<<endl;
        } else {
            cout<<"1 "<<last_u<<" "<<a[i]+1<<endl;
            last_u = a[i]+1;
            last_ans = a[i];
        }
    }
}
signed main(){
    int T;
    cin>>T;
    while (T--)
        solve();
}
