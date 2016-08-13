#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 10005
#define INF 10000000000000
using namespace std;

typedef long long ll;

int a[105][105];
int b[105];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) scanf("%d", &a[i][j]);

    if(n == 1) {
        printf("%d\n", a[0][0]);
        continue;
    }
    int p = 0;
    b[p++] = a[0][0];

    int da = 1, db = -1;
    int c = 0, d = 1;
    while(c != n - 1 || d != n - 1) {
      do {
        b[p++] = a[c][d];
        c += da;
        d += db;
      } 
      while(0 < c && c < n - 1 && 0 < d && d < n - 1);
      b[p++] = a[c][d];
      if(d == 0 && c < n - 1) {
            c++;
      }
      else if(c == n - 1) {
            d++;
      }
      else if(c == 0 && d < n - 1) {
            d++;
      }
      else {
            c++;
      }
      da *= -1;
      db *= -1;

    }
    b[p++] = a[n - 1][n - 1];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        printf("%d ", b[i * n + j]);
      }
      printf("\n");
    }
  }

  return 0;
}
