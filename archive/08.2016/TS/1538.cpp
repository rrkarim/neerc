#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
using namespace std;

typedef long long ll;
int n, m, maxn1, maxn2, x, y, found = 0;
pair <ll, ll> a[5005];

bool check(int b[], int len) {
    if(b[0] == 2 && b[1] == 1 && b[2] == 4 && b[3] == 5 && b[4] == 3) {
        for(int i = 0; i < len; ++i) cout << b[i] << " ";
        cout << endl;
    }
    ll res = 0, ans = 0;
    for(int i = 2; i < len; ++i) {
        int p3 = i;
        int p2 = (i + 1) % len;
        int p1 = (i + 2) % len;


        ll x1 = a[p2].first - a[p1].first;
        ll y1 = a[p2].second - a[p1].second;
        ll x2 = a[p3].first - a[p2].first;
        ll y2 = a[p3].second - a[p2].second;

        if(i == 2) {
            res = x1 * y2 - x2 * y1;
        }
        else {
            ans = x1 * y2 - x2 * y1;
            if(b[0] == 2 && b[1] == 1 && b[2] == 4 && b[3] == 5 && b[4] == 3)
                cout << res << " " << ans << endl;
            if( (ans > 0 && res < 0) || (ans < 0 && res > 0)) {
                return false;
            }
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < 5; ++i) cout << b[i] << " \n"[i == 4];
    exit(0);
    return true;
}

bool solve(int mask) {
    int b[10], len = 0;
    for(int j = 0; j < min(n, 9); ++j) {
        if(mask & (1 << j)) {
            b[len++] = j;
        }
    }


    sort(b, b + len);
    do {
        check(b, len);
    }
    while (std::next_permutation(b, b + len));
    return false;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    for(int i = 0; i < (1 << min(n, 9)); ++i) {
        if(__builtin_popcount(i) != 5) continue;
        solve(i);
    }
    cout << "No" << endl;
}

