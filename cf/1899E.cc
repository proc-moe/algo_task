#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
#define int long long
int a[N];
void solve(){
    int n;
    cin>>n;
    int min_id = 0;
    int minn = LONG_LONG_MAX;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i] < minn ){
            min_id = i;
            minn = a[i];
        }
    }
    for (int i=min_id+1;i<=n;i++){
        if (a[i] < a[i-1]) {
            cout<<"-1"<<endl;
            return;
        } 
    }
    cout<<min_id-1<<endl;
}
signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}