#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        int a[n];
        int x;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        int now = a[0];
        for (int i=1;i<n;i++){
            if (a[i] == 0) {
                now = now * 0;
            } else if (a[i]>0){
                now = now * 1;
            } else {
                now = now * -1;
            }
        }

        if (now>0){
            cout<<"1"<<endl;
            for (int i=0;i<n;i++){
                if (a[i]!=0){
                    cout<<i+1<<" 0"<<endl;
                    break;
                }
            }
        } else {
            cout<<0<<endl;
        }
    }
}