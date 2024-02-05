#include <bits/stdc++.h>
using namespace std;
int a[1000];
void solve(){
    int n;
    cin>>n;
    int  minn = -1;
    int  maxx = 1e9+1;
    int len = 0;
    for (int i=1;i<=n;i++){
        int k,xx;
        cin>>k>>xx;
        if (k==1){
            minn = max(minn,xx);
        } else if (k==2) {
            maxx = min(maxx, xx);
        } else if (k==3) {
            a[len++] = xx;
        }
    }
    bool have = true;
    sort(a,a+len);
    int tot = maxx - minn + 1;
    for (int i=0;i<len;i++){
        if (a[i]>=minn && a[i]<=maxx){
            tot-=1;
        }
    }
    cout<<max(tot,0)<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}