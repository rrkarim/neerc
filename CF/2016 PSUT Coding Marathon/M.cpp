/**
*/
#include <bits/stdc++.h>
#define MAXN 211005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
char c;
int n, a[400];
vector <int> v;
int mp[MAXN + 2], inc = 100004;
int solve() {
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            v.push_back(a[i]);
            mp[ a[i] + inc ] = 1;
        }
        else {
            vector <pair <int, int>> vi;
            for(int j = 0; j < v.size(); ++j) {
                int d = mp[v[j] + inc];
                vi.push_back({v[j] + a[i], d});
                vi.push_back({v[j] - a[i], d + 1});
            }
            for(int j = 0; j < v.size(); ++j) mp[v[j] + inc] = 0;
            v.clear();
            for(int j = 0; j < vi.size(); ++j) {
                if(mp[vi[j].first + inc] == 0) {
                    mp[vi[j].first + inc] = vi[j].second;
                    v.push_back(vi[j].first);
                }
                else mp[vi[j].first + inc] = min(mp[vi[j].first + inc], vi[j].second);
            }
        }
    }
    if(mp[inc] == 0) return -1;
    return mp[inc] - 1;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        if(!i) cin >> a[i];
        else {
            cin >> c >> a[i];
            a[i] *= (c == '+' ? 1 : -1 );
        }
    }
    cout << solve() << endl;
}