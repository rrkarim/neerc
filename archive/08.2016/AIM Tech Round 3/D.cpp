#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
using namespace std;

typedef long long ll;

string s;

int check(ll a) {
    for(int i = 1; i <= 1000000; ++i) {
        ll x = 1ll * i * (i - 1) / 2;
        if(x == a) return i;
    }
    return -1;
}

int main() {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        int n = check(a);
        int m = check(d);

        if(n == -1 || m == -1) {
            cout << "Impossible" << endl;
            return 0;
        }
        if(a == 0 && b == 0 && c == 0 && d == 0) {
            cout << "0" << endl;
            return 0;
        }

        if(n == 1 && b == 0 && c == 0) n = 0;
        if(m == 1 && b == 0 && c == 0) m = 0;

        int dx = n + m;
        for(int i = 0; i < dx; ++i) {
            if(b - m >= 0) {
                b -= m;
                n -= 1;
                s += '0';
            }
            else if(c - n >=0) {
                c -= n;
                m -= 1;
                s += '1';
            }
        }
        if(b == 0 && c == 0 && s.length() == dx) cout << s << endl;
        else cout << "Impossible" << endl;
}
