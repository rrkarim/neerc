/**
*/
#include <bits/stdc++.h>
#define MAXN 211005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
char c;
ll a[50];
int n, res = MAXN;
int solve() {
    for(int i = 0; i < (1 << (n - 1)); ++i) {
        ll sum = a[0], f = 0;
        for(int j = 0; j < n - 1; ++j) {
            if(i & ( 1 << j)) sum -= a[j + 1], f += 1;
            else sum += a[j + 1];
        }
        if(f < res && sum == 0) res = f;
    }
    if(res == MAXN) return -1;
    return res;

}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        if(!i) cin >> a[i];
        else {
            cin >> c >> a[i];
            a[i] *= (c == '+' ? 1 : -1 );
        }
    }
    cout << solve() << endl;
}
