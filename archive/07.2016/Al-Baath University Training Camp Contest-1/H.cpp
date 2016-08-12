/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;

int n, d, r, used1[MAXN + 2], used2[MAXN + 2];

int gcd ( int a, int b ) { int c; while ( a != 0 ) { c = a; a = b%a; b = c; } return b; }
int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> d >> r;
        memset(used1, 0, sizeof used1);
        memset(used2, 0, sizeof used2);
        int x = d, y = r;
        used1[x] = 1, used2[y] = 1;
        if(x == y) {
            cout << 1 << endl;
            continue;
        }
        for(int k = 2; k <= 100000; ++k) {
            x = (x + d) % n;
            y = (y + r) % n;
            if(x == y || used2[x] || used1[y]) {
                cout << k << endl;
                break;
            }
            used1[x] = 1, used2[y] = 1;
        }
        
    }
}
