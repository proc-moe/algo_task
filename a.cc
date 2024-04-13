#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+10;
vector<int> primes;

int get_primes(){
    vector<int> prime(N);
    prime.clear();
    prime[1] = 0;
    for (int i=2;i<N;i++) {
        if (prime[i] == 0) {
            primes.push_back(i);
            for (auto j: primes) {
                if (i * j > N) break;
                prime[j * i] = 1;
                if (i % j == 0) {
                    break;
                }
            }
        }
        
    }

}
void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int a1 = a % 2;
    int b1 = b % 2;
    int c1 = c % 2;
    int d1 = d % 2;
    int ans = (a / 2) + (b/2) + (c/2) + (d/2);
    if (a1 == b1 &&  b1 == c1 && c1 == 1) {
        ans++;
    }
    cout<<ans<<endl;
}

signed main(){
    get_primes();
    for (int i=0;i<10;i++) {
        cout<<primes[i]<<endl;
    }

    // int T;
    // cin>>T;
    // while (T--) solve();
}