#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 2e5+10;
int a[N];
int b[N];
int dp[N];
int maxx[N];
void doo(int l,int r){
    maxx[l] = a[l];
    for (int id=l+1;id<=r;id++){
        if (maxx[id-1] + a[id] > a[id]) maxx[id] = maxx[id-1] + a[id];
        else {
            maxx[id] = a[id];
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int len = 1;
    b[1] = 1;
    for (int i=2;i<=n;i++){
        if (abs(a[i]%2) == abs(a[i-1]%2)) {
            len ++;
            b[len] = i;
        }
    }
    b[len+1] = n+1;
    for (int i=1;i<=len;i++){
        int l = b[i];
        int r = b[i+1]-1;
        doo(l,r);
    }
    int res = LONG_LONG_MIN;
    for (int i=1;i<=n;i++){
        res = max(res, maxx[i]);
    }
    cout<<res<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
}