#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;

int main() {
    int n; cin >> n;
    double all_r = 0.0, all_t = 0.0, r, v;
    while(n--) {
        cin >> r >> v;
        all_r += r;
        all_t += r / v;
    }
    cout << fixed << setprecision(7) << all_r / all_t << endl;
}
