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
bool check() {
    for(int i = 0; i < a.size() - 3; ++i) {
        for(int j = 0; j < 5; ++j) {
            string temp;
            for(int z = 0; z < 4; ++z) {
                if(z == j) temp += '.';
                temp += a[min(i + z, (int)a.size() - 1)];
            }
            if(j == 4) temp += '.';
            for(int z = 0; z < 2; ++z) {
                int found = 1;
                for(int x = 0; x < 4; ++x) {
                    if(temp[min(z + x,4)] == '.') continue;
                    if(temp[min(z + x,4)] != b[x]) found = 0;
                }
                if(found) return 1;
            }
        }
    }
    return 0;
}
int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> a >> b;
        if(a.size() < b.size()) {
            cout << "none" << endl;
            continue;
        }
        int found = 0;
        for(int i = 0; i < a.size() - 3; ++i) {
            int f = 1;
            for(int j = 0; j < 4; ++j) {
                if(a[i + j] != b[j]) {
                    f = 0;
                }
            }
            if(f == 1) {
                found = 1;
                break;
            }
        }
        if(found) {
            cout << "good" << endl;
            continue;
        }
        if(check()) cout << "almost good" << endl;
        else cout << "none" << endl;
    }
}
