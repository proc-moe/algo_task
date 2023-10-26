#include <bits/stdc++.h>
using namespace std;
int T;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    int mex = 0;
    for (mex=0;mex<n;mex++) {
        if (v[mex] != mex){
            break;
        }
    }
    while (1){
        cout<<mex<<endl;
        cout.flush();
        cin>>mex;
        if (mex == -1) {
            break;
        }
    }
}
int main(){
    cin>>T;
    while (T--) solve();
}