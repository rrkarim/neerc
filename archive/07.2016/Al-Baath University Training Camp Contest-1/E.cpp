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

int gcd ( int a, int b ) { int c; while ( a != 0 ) { c = a; a = b%a; b = c; } return b; }
int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        int sum = 0, gcd_ = -1;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            gcd_ = (gcd_ == -1 ? x : gcd(gcd_, x));
            sum += x;
        }
        cout << gcd_ << " " << sum / gcd_ << endl;
    }
}