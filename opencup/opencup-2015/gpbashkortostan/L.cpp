#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;
typedef long long ll;
int d[9][11];
int x[9];
ll f(ll n);
long long dd(ll n);

ll f(ll n) {
    ll d = n / 2;
    if(d % 2) {
        return dd(d) + n;
    }
    else return f(d) + n;
}

ll dd(ll n) {
    if(n == 1) return 0;
    ll d = 3 * (n / 2) + 2;
    if(d % 2) {
        return dd(d) + n + 1;
    }
    else return f(d) + n + 1;
}

int main() {
    ll n; cin >> n;
    if(n % 2) {
        cout << dd(n) << endl;
    }
    else cout << f(n) << endl;
}
