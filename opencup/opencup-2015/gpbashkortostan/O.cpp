#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;
int d[9][11];
int x[9];
int main() {
        for(int i = 0; i < 11; ++i) d[1][i] = 1; x[1] = 9;
        for(int i = 2; i <= 8; ++i) {
            for(int j = 0; j < 10; ++j) {
                if(j == 0) {
                    d[i][j] = d[i - 1][j + 1];
                }
                else if(j == 9) {
                    d[i][j] = d[i - 1][j - 1];
                }
                else {
                    d[i][j] = d[i - 1][j - 1];
                    d[i][j] += d[i - 1][j + 1];
                }
                if(j != 0) x[i] += d[i][j];
            }
        }
        int n, len = 0, prev = -1; cin >> n;
        int dd = 0;
        for(int i = 1; i <= 8; ++i) { dd += x[i]; if(dd >= n) { len = i; break; } }
        for(int i = len; i >= 1; --i) {
            if(prev == -1) {
                int res = 0;
                for(int j = 1; j <= i - 1; ++j) res += x[j];
                for(int j = 1; j <= 9; ++j) {
                    res += d[i][j];
                    if(res >= n) {
                        res -= d[i][j];
                        n -= res;
                        prev = j;
                        cout  << j;
                        break;
                    }
                }
            }
            else {
                if(prev == 0){
                    prev = 1;
                    cout << prev;
                }
                else if(prev == 9) {
                    prev = 8;
                    cout << prev;
                }
                else {
                    //cout << "//" << n << endl;
                int res = 0;
                for(int j = 1; j <= i - 1; ++j) res += x[j];
                    res = d[i][prev - 1];
                    if(res >= n) {
                        res -= d[i][prev - 1];
                        n -= res;
                        cout << prev - 1;
                        prev = prev - 1;
                        continue;
                    }
                    n -= res;
                    cout << prev + 1;
                    prev = prev + 1;
                }
            }

        }
        cout << endl;
}
