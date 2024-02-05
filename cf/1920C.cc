#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
ll a[N];

vector<int> get_factor(int n){
    int sqrtn = floor(sqrt(n));
    vector<int> vec;
    
    for (int i=1;i<=sqrtn;i++) {
        if (n % i == 0) {
            vec.push_back(i);
            vec.push_back(n/i);
        }
    }
    sort(vec.begin(), vec.end());
    return vec;
}

void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    auto vec = get_factor(n);
    for (auto cut: vec){
            
    }
}
int main(){
    solve();
}