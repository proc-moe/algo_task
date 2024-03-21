#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int x = 1;
    while (x < n){
        if (s1[x] > s2[x-1]) {
            break;
        }
        x+=1;
    }
    string minimum = "";
    for (int i=0;i<x;i++){
        minimum += s1[i];
    }
    for (int i=x-1;i<n;i++){
        minimum += s2[i];
    }
    x-=1;
    int ans = 1;
    while (x>=1 && s1[x] == s2[x-1]) {
        ans += 1;
        x -= 1;
    }
    cout<<minimum<<endl;
    cout<<ans<<endl;
}

signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}