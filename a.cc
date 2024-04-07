#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define int long long
using namespace std;

unordered_map<int,int> mp1,mp2;
void solve() {
mp1.clear();
mp2.clear();
    int n;
    int k;
    cin>>n>>k;
    int a[n],b[n];

    for (int i=0;i<n;i++){
        cin>>a[i];
        mp1[a[i]]++;
    }
    for (int i=0;i<n;i++){
        cin>>b[i];
        mp2[b[i]]++;
    }

    vector<int> v1,v2;
    vector<int> o1,o2;
    for (auto x = mp1.begin(); x != mp1.end(); x++){
        if (x->second == 2) {
            v1.push_back(x->first);
        } else {
            o1.push_back(x->first);
        }
    }

        for (auto x = mp2.begin(); x != mp2.end(); x++){
        if (x->second == 2) {
            v2.push_back(x->first);
        } else {
            o2.push_back(x->first);
        }
    }

    int r = k * 2;
    unordered_set<int> choose1;
    unordered_set<int> choose2;

    auto iter = v1.begin();
    auto iter2 = v2.begin();
    while (r) {
        if (iter == v1.end()) {
            for (int i=0;i<r;i++){
                choose1.insert(o1[i]);
                choose2.insert(o1[i]);
            }
            break;
        }
        choose1.insert(*iter);
        choose2.insert(*iter2);
        iter++;
        iter2++;
        r -= 2;
    }
    for (int i=0;i<n;i++){
        if (choose1.find(a[i]) != choose1.end()){
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
    for (int i=0;i<n;i++){
        if (choose2.find(b[i]) != choose2.end()){
            cout<<b[i]<<" ";
        }
    }
    cout<<endl;
}

signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}