/**
*/
#include <bits/stdc++.h>
#define MAXN 50005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;

int n, m, x, y, c, r, r1, c1, r2, c2;
string a, b;
char ma[1005][1005],cz;

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> m >> x;
        for(int i = 0; i < 1003; ++i) for(int j = 0; j < 1003; ++j) ma[i][j] = '.';
        for(int i = 0; i < x; ++i) {
            cin >> r1 >> c1 >> r2 >> c2 >> cz;
            for(int i = r1 - 1; i < r2; ++i)
                for(int j = c1 - 1; j < c2; ++j) ma[i][j] = cz;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                printf("%c", ma[i][j]);
            }
            printf("\n");
        }
    }
}
