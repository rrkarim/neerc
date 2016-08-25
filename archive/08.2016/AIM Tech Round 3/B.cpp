#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
using namespace std;

typedef long long ll;
ll x[MAXN + 2];
vector <ll> am, bm;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, a; cin >> n >> a;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x, x + n);
    for(int i = 0; i < n; ++i) {
        if(x[i] < a) {
            am.push_back(x[i]);
        }
        else if(x[i] > a) {
            bm.push_back(x[i]);
        }
    }
    if(am.empty() && !bm.empty()) {
        ll res = 0;
        if(bm.size() == 1) res = 0;
        else res = bm[bm.size() - 2] - a;
        cout << res << endl;
    }
    else if(bm.empty() && !am.empty()) {
        ll res = 0;
        if(am.size() == 1) res = 0;
        else res = a - am[1];
        cout << res << endl;
    }
    else if(am.empty() && bm.empty()) {
        cout << 0 << endl;
        return 0;
    }
    else {
        ll left = 0, right = 0, res1, res2;
        left = (am.size() == 1 ? 0 : a - am[1]), right = bm[bm.size() - 1] - a;
        res1 = min(2ll * left + right, 2ll * right + left);
        left = a - am[0];
        right = (bm.size() == 1 ? 0 : bm[bm.size() - 2] - a);
        res2 = min(2ll * left + right, 2ll * right + left);

        res1 = min(res1, res2);

        cout << res1 << endl;

    }
}