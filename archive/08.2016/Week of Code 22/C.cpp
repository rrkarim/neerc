#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 200005
#define INF 1000000
using namespace std;

typedef long long ll;
int n, x, y, s, f;
ll a[MAXN + 2], b[MAXN + 2], suma, sumb, xs;
vector <ll> as, bs;
map <ll, int> mp1, mp2;
int main() {

    int n; cin >> n;
    for(int i = 0; i < n; ++i) scanf("%lld", a+i), suma += a[i], mp1[a[i]] += 1;
    for(int i = 0; i < n; ++i) scanf("%lld", b+i), sumb += b[i], mp2[b[i]] += 1;

    if(suma != sumb) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        if(mp2[ a[i] ]) mp2[a[i]] -= 1;
        else as.push_back(a[i]);
    }
    for(int i = 0; i < n; ++i) {
        if(mp1[ b[i] ]) mp1[b[i]] -= 1;
        else bs.push_back(b[i]);
    }

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    ll res = 0;
    for(int i = 0; i < as.size(); ++i) if(as[i] > bs[i]) res += as[i] - bs[i];
    
    cout << res << endl;
}
