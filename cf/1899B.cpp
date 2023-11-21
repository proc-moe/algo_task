#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 150005;
int a[N];
void solve(){
    int n;
    cin>>n;
    
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i] = a[i-1] + x;
    }
    int sqrtn = floor(sqrt(n));
    int max_dis = LONG_LONG_MIN;
    for (int k=1;k<=sqrtn;k++){
        if (n%k==0){
            int start = 0;
            int end = k;
            int maxx = LONG_LONG_MIN;
            int minn = LONG_LONG_MAX;
            while (start < n){
            maxx = max(maxx,a[end]-a[start]);
            minn = min(minn,a[end]-a[start]);
            start += k;
            end += k;
            }
            max_dis = max(max_dis,maxx-minn);
            int kk = n / k;
            start = 0;
            end = kk;
            maxx = LONG_LONG_MIN;
            minn = LONG_LONG_MAX;
            while (start < n){
            maxx = max(maxx,a[end]-a[start]);
            minn = min(minn,a[end]-a[start]);
            start += kk;
            end += kk;
            }
            max_dis = max(max_dis,maxx-minn);
        }
        
    }
    cout<<max_dis<<endl;
}
signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}