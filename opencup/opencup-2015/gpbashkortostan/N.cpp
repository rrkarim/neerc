#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;
typedef long long ll;

int main() {
    int t, n, x; cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> x;
        if(x > n) {
            cout << "NO" << endl; continue;
        }
        int xx = 0;
        ll d = (n + 1) * n / 2;
        if(d % 2) xx = 0;
        else xx = 1;
        if(x % 2) {
            if(xx == 1) xx = 0;
            else xx = 1;
        }
        cout << (xx == 1 ? "YES" : "NO") << endl;
    }
}
