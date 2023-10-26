#include <bits/stdc++.h>
using namespace std;
int a[200];
void solve(){
    int n;
    cin>>n;
    int maxx = 0;
    for (int i=1;i<=n;i++){
        maxx += 1;
        int x;
        cin>>x;
        if (maxx == x) {
            maxx += 1;
        }
    }
    cout<<maxx<<endl;
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}