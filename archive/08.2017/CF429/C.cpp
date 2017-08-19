nclude <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 200004

using namespace std;
#define fir first
#define sec second
#define pb push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

const ll mod = 1e9 + 7ll;

ll a[MAXN + 2], x;
pair <ll, int> b[MAXN + 2];

bool cmp(pair<ll, int> &left, pair<ll, int> &right) {
    return left.first > right.first;
}

ll c[MAXN + 2];

int main() {
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) {
        cin >> x;
        b[i] = {x, i};
    }
    sort(b, b + n, cmp);
    sort(a, a + n);

    for(int i = 0; i < n; ++i) c[b[i].second] = a[i];
    for(int i = 0; i < n; ++i) cout << c[i] << ' ';


    return 0;
}
