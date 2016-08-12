/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;

int m, ks = 1, index;
ll k, a[MAXN + 2], sum, maxn, s = 0, res = 0;
vector <ll> vi;
int main() {
    scanf("%d%I64d", &m, &k);
    for(int i = 0; i < m; ++i) scanf("%I64d", a + i), sum += a[i];
    maxn = sum / m + (sum % m != 0);
    sort(a, a + m);

    for(int i = 0; i < m; ++i) {
        if(a[i] >= maxn) {
            vi.push_back(a[i]);
        }
    }
    index = vi.size() - 1;
    res = vi[index];

    while(true) {
        if(k == 0) break;
        if(vi[index] == maxn) {
            res = maxn;
            break;
        }
        if(index == 0) {
            ll d = k / ks;
            res = vi[index] - d;
            break;
        }
        ll f = (vi[index] - vi[index - 1]) * ks;
        if(f <= k) {
            k -= f;
            index -= 1;
            ks += 1;
        }
        else {
            ll d = k / ks;
            res = vi[index] - d;
            break;
        }
    }
    cout << max(maxn, res) << endl;


}
