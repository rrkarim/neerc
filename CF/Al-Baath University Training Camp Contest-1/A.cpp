/**
*/
#include <bits/stdc++.h>
#define MAXN 50005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
int n, m, x, y, c, r;

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> r;
        int x = 1500;
        for(int i = 0; i < n; ++i) {
            cin >> c;
            x += c;
        }
        cout << (x == r ? "Correct" : "Bug") << endl;
    }
}
