/**
    Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define MAXN 1000000
#define INF 2000000
#define _INF -20000000
#define RANDOM_INIT()	srand(time(NULL))
#define RANDOM(L, R)	(L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

char c;
int usedR[MAXN + 2], usedC[MAXN + 2];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, q, t;
    ll uR = 0, uC = 0, xR = 0, xC = 0;
    cin >> n >> q;

    ll init = (n + 2) * (n + 1) / 2 - 1;
    for(int i = 0; i < q; ++i) {
        cin >> c >> t;
        if(c == 'R') {
            if(usedR[t]) {
                cout << "0" << endl;
                continue;
            }
            cout << t * (n - xR) + (n + 1) * n / 2 - uR << endl;
            uC += t;
            xC += 1;
            usedR[t] = 1;
        }
        else {
            if(usedC[t]) {
                cout << "0" << endl;
                continue;
            }
            cout << t * (n - xC) + (n + 1) * n / 2 - uC << endl;
            uR += t;
            xR += 1;
            usedC[t] = 1;
        }
    }
}
