#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int a[N];
int b[N];
int p[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        cin>>a[i];
    }
    b[1] = a[1];
    p[b[1]] = 1;
    for (int i=2;i<n;i++){
        b[i] = a[i] ^ b[i-1];
        p[b[i]] = 1;
    }

    int k = 0;
    for (int i=1;i<n;i++){
        if (p[i] == 0){
            k = p[i];
            break;
        }
    }
    
    int tmp = k;
    for (int i=1;i<n;i++) tmp = tmp^b[i];
    b[0] = tmp;
    for (int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}