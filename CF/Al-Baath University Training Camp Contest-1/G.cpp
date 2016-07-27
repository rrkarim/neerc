/**
*/
#include <bits/stdc++.h>
#define MAXN 50005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;

ll h, w, ds;
string a, b;
int gcd ( int a, int b ) { int c; while ( a != 0 ) { c = a; a = b%a; b = c; } return b; }
int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
            cin >> h >> w >> ds;
            w -= 1;
            ll d = h % w;
            d = h - d;
            ll c = d / w;
            d += 1;
            if(d > h) d -= w, c -= 1;
            w += 1;
            if(c % 2) {
                if(w - (h - d) == ds) cout << "Yes" << endl;
                else cout << "No" << endl;
            }  
            else {
                if(1ll + (h - d) == ds) cout << "Yes" << endl;
                else cout << "No" << endl; 
            }
        
    }
}
