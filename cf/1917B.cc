#include <bits/stdc++.h>
using namespace std;
#define int long long
set<int> ss;
void solve(){
    int n;
    int tot = 0;
    string s;
    cin>>n;
    cin>>s;
    ss.clear();
    for (int i=0;i<s.length();i++){
        ss.insert(s[i]);
        tot += ss.size();
    }
    cout<<tot<<endl;
}
signed main(){
    int T;
    cin>>T;
    while (T--){
        solve();
    }
}