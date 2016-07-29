/**
    Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
string s, c;
int n;

vector <string> ans;

int main() {
    //freopen("fraud.in", "r", stdin);
    //freopen("fraud.out", "w", stdout);
    cin >> s >> n;
    for(int i = 0; i < n; ++i) {
        cin >> c;
        int f = 1;
        for(int j = 0; j < c.size(); ++j) {
            if(s[j] == '*') continue;
            if(s[j] != c[j]) {
                f = 0;
                break;
            }
        }
        if(f) ans.push_back(c);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
}
