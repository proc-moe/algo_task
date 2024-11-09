#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s = "";
    int ans;
    cout <<"? 0" << endl;
    cin >> ans;
    if (ans == 0) {
        s = "1";
    } else {
        s = "0";
    }
    int back_forwarding = 1;
    while (s.length() < n) {
        if (back_forwarding) {
            cout << "? " + s + "0" << endl;
            int ans;
            cin >> ans;
            cout << "? " + s + "1" << endl;
            int ans2;
            cin >> ans2;
            if (ans == 0 && ans2 == 0) {
                back_forwarding = 0;
            } else if (ans == 1) {
                s = s + "0";
            } else if (ans2 == 1) {
                s = s + "1";
            }
        } else {
            cout << "? 0" + s << endl;
            int ans;
            cin >> ans;
            if (ans == 0) {
                s = "1" + s;
            } else {
                s = "0" + s;
            }
        }
    }
    cout <<"! " << s << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}