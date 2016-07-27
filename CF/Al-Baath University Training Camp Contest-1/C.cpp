/**
*/
#include <bits/stdc++.h>
#define MAXN 50005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;

int n, m, x, y, c, r;
string a, b;

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        ll res = 1ll;
        cin >> n >> a >> b;
        for(int i = 0; i < a.size(); ++i) {
            if((a[i] == '0' && b[i] == '1') || (a[i] == '0' && b[i] == '0')) continue;
            else if(a[i] == '1' && b[i] == '0') res = 0;
            else res = (res * 2ll) % mod;
        }
        if(!res) cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;
    }
}
