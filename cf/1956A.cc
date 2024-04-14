#include <bits/stdc++.h>
#define int long long
using namespace std;
 
void solve() {
    vector<int> v;
    int k,q;
    v.clear();
    cin>>k>>q;
    for (int i=0;i<k;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<q;i++){
        int n;
        cin>>n;
        int tmp = n;
        while (1) {
            int to_del = 0;
            for (auto x: v) {
                if (x <= tmp) {
                    to_del++;
                } else {
                    break;
                }
            }
            if (to_del == 0) {
                break;
            }
            tmp -= to_del;
        }
        cout<<tmp<<" ";
    }
 
    cout<<endl;
}
 
signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}