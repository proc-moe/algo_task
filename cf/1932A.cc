#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    string s;
    cin>>n>>s;
    int maxx = n;
    for (int i=1;i<n;i++){
        if (s[i] == '*' && s[i] == s[i-1]) {
            maxx = i;
            break;
        }
    }
    int res = 0;
    for (int i=1;i<maxx;i++) {
        if (s[i] == '@') res++;
    }

    cout<<res<<endl;
}
int main() {
    int T;
    cin>>T;
    while (T--) solve();
}