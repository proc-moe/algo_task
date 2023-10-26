#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int len[500];
int val[500][500];
map<string,int> mp;
vector<int> appeared_number;
void solve(){
    mp.clear();
    appeared_number.clear();
    a.clear();
    int n;
    cin>>n;
    a.resize(51);
    for (int i=1;i<=n;i++) {
        int k;
        cin>>len[i];
        for (int j=1;j<=len[i];j++){
            int p;
            cin>>val[i][j];
            a[val[i][j]].push_back(i);
        }
    }
    for (int i=1;i<=50;i++){
        if (a[i].size() > 0) appeared_number.push_back(i);
    }
    int maxx = 0;
    for (int i=0;i<appeared_number.size();i++){
        int value_to_delete = appeared_number[i];
        unordered_set<int> number_in_S;
        number_in_S.clear();

        unordered_set<int> set_to_del;
        set_to_del.clear();
        for (int j=0;j<a[value_to_delete].size();j++) set_to_del.insert(a[value_to_delete][j]);

        unordered_set<int> set_to_fill;
        set_to_fill.clear();
        for (int j=1;j<=n;j++){
            if (set_to_del.find(j) == set_to_del.end()){
                set_to_fill.insert(j);
            }
        }

        for (auto &set_id: set_to_fill){
            for (int j=1;j<=len[set_id];j++){
                number_in_S.insert(val[set_id][j]);
            }
        }
        maxx = max(maxx,int(number_in_S.size()));
    }
    cout<<maxx<<endl;
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}