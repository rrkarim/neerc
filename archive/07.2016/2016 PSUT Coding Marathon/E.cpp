/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int n, m, dp[30][30], used[MAXN + 2], x, y, r, q, t, index[MAXN + 200];
string a, b;
int c = 0;

bool check() {
    if(a.size() < 8) return 0;
    if(a.size() == b.size()) {
        int c = 0;
        for(int j = 0; j < min(a.size(), b.size()); ++j) {
            if(a[j] != b[j]) c += 1;
        }
        if(c == 1) return 1;
        return 0;
    }
    if(a.size() < b.size()) return 0;
    for(int i = 0; i < a.size(); ++i) {
        string temp = a;
        temp.erase(i, 1);
        int c = temp.size() - b.size();
        for(int j = 0; j < min(temp.size(), b.size()); ++j) {
            if(temp[j] != b[j]) c += 1;
        }
        if(c == 0) return 1;
    }
    return 0;
}

int main() {
    //freopen("bonus.in", "r", stdin);
    //freopen("bonus.out", "w", stdout);
    /*
    int n, m; cin >> n >> m;
    for(int i = 0; i < n + 1; ++i)
        for(int j = 0; j < m + 1; ++j)
            cin >> dp[i][j];
    */

    cin >> a >> b;
    c = (b.length() > a.length() ? (b.length() - a.length()) : (a.length() - b.length()));
    for(int i = 0; i < min(a.size(), b.size()); ++i)
        c += (a[i] != b[i]);

    if(c == 0 || check()) cout << "yes" << endl;
    else cout << "no" << endl;
}
