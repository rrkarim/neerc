#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 100005
using namespace std;

typedef long long ll;

ll mod = (1ll << 20);

int next(int& n) {
    return n = (1ll * 487237 * n + 1011807) % mod;
}
int s[30];
void solve() {

    int t; cin >> t;
    for(int i = 0; i < 25; ++i) {
        cout << 1 << endl;
        int nt; cin >> nt;
        if(nt == -1) return;
        s[i] = (nt > t);
        t = nt;
    }
    int fin = -1;
    for(int i = 0; i < (1 << 20); ++i) {
        int q = i;
        for(int j = 0; j < 25; ++j) {
            int fl = __builtin_popcount(q) & 1;

            if(s[j] != fl) {
                break;
            }
            if(j == 24) {
                fin = q;
            }

            next(q);
        }
        if(fin != -1) break;
    }

    int q = fin;
	while (1) {
		q = next(q);
		int v = __builtin_popcount(q) & 1;
		if (v&1) {
			cout << t << endl;
			cin >> t;
		} else {
			cout << 1 << endl;
			cin >> t;
		}
		if (t == -1) return;
	}

}

int main() {
    solve();
}
