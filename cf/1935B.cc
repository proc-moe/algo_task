#include <bits/stdc++.h>
#include <queue>
using namespace std;
void solve() {
    priority_queue<int> l,r;
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> mexl(n);
    vector<int> mexr(n);
    vector<int> ansl(n);
    vector<int> ansr(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    mexl.resize(n+1);
    mexr.resize(n+1);
    ansl.resize(n+1);
    ansr.resize(n+1);
    int now = 0;
    for (int i=0;i<n;i++){
        mexl[a[i]]++;
        while (mexl[now] != 0) {
            now+=1;
        }
        ansl[i] = now;
    }
    now = 0;
    for (int i=n-1;i>=0;i--){
        mexr[a[i]]++;
        while (mexr[now] != 0) {
            now+=1;
        }
        ansr[i] = now;
    }

    for (int i=0;i<n-1;i++){
        int lefter = i;
        int righter = i+1;
        if (ansl[lefter] == ansr[righter]) {
            cout<<2<<endl<<1<<" "<<lefter+1<<endl<<righter+1<<" "<<n<<endl;
            return;
        }
    }
    cout<<-1<<endl;
    return;
}
int main() {
    int T;
    cin>>T;
    while (T--) solve();
}