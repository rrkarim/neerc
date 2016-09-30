#include <bits/stdc++.h>
#include <string>
using namespace std;
pair <int, int> vi[1005];
map<pair<int,int>,int> u;
vector <pair<int, int> > ans;

vector <int> f(int l, int r) {
    vector <int> ret;
    if(l == r) { ret.push_back(vi[l].second); return ret;}
    int m = (l + r) / 2;
    int x = vi[m].first;
    vector<int> ld = f(l, m);
    vector<int> rd = f(m+1, r);
    for(int i = 0; i < ld.size(); ++i) {
        if(u[{x,ld[i]}] != 1) {
            u[{x,ld[i]}] = 1;
            ans.push_back({x, ld[i]});
        }
    }
    for(int i = 0; i < rd.size(); ++i) {
        if(u[{x,rd[i]}] != 1) {
            u[{x,rd[i]}] = 1;
            ans.push_back({x, rd[i]});
        }
    }
    for(int i = 0; i < rd.size(); ++i) ld.push_back(rd[i]);
    return ld;
}
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> vi[i].first >> vi[i].second;
        u[{vi[i].first, vi[i].second}] = 1;
    }
    sort(vi, vi + n);
    f(0, n - 1);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

