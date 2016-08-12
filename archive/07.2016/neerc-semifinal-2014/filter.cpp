/**
    Rasul Kerimov (CoderINusE)
    Filter
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()   srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

int m, f, a[105], q, h[1005][1005];
int b[1005], dj[1005], n;
string s;
int main() {
    cin >> m >> f;
    for(int i = 0; i < f; ++i) cin >> a[i];
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        for(int j = 0; j < s.length(); ++j)
            h[i][j] = (s[j] >= '0' && s[j] <= '9' ? s[j] - '0' : s[j] - 'a' + 10);
    }
    cin >> q;
    ll temp;
    int ans = 0;
    for (int i = 0; i < q; i++) {
        cin >> temp;
        for (int j = 0; j < f; j++) dj[j] = (int)((temp * a[i]) % m);
        for (int j = 0; j < n; j++) {
            bool ald = 1;
            for (int z = 0; z < f; z++) {
                if ((h[j][dj[z] / 4] & (1 << (dj[z] % 4))) == 0)
                    ald = false;
            }
            if (ald && !b[j]) {
                b[j] = true;
                ans++;
            }
        }
    }
    cout << ans;
    for(int i = 0; i < n; ++i) if(b[i]) {
        cout << " " << i;
    }
    cout << endl;

}
