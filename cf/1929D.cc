#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    stack<pair<int,int>> st;
    cin >> n;
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (st.empty()) {
            st.push(make_pair(1, x));
        } else if (x > st.top().second) {
            st.push(make_pair(1, x));    
        } else if (x == st.top().second) {
            auto [cnt, value] = st.top();
            st.pop();
            st.push(make_pair(cnt + 1, value));
        } else {
            st.push(make_pair(1, x));
            auto [cnt, value] = st.top();
            st.pop();
            auto [cnt2, value2] = st.top();
            st.pop();
            int tot = cnt * value + cnt2 * value2;
            int tot_cnt = cnt + cnt2;
            while (1) { 
                if (st.empty() || tot / tot_cnt <= st.top().second) {
                    break;
                }
                auto [cnt3, value3] = st.top();
                st.pop();
                tot += (cnt3 * value3);
                tot_cnt += cnt3;
            }
            int v1 = tot / tot_cnt;
            int c1 = tot_cnt - (tot % tot_cnt);
            int v2 = tot / tot_cnt + 1;
            int c2 = tot % tot_cnt;
            st.push(make_pair(c1,v1));
            if (c2 != 0) {
                st.push(make_pair(c2,v2));
            }
        }
    }
    int min = LONG_LONG_MAX;
    int max = LONG_LONG_MIN;
    while (!st.empty()) {
        auto [cnt, now] = st.top(); st.pop();
        if (now < min) min = now;
        if (now > max) max = now;
    }
    cout << max - min << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}