/**
    Rasul Kerimov (CoderINusE)
    Burrito King
*/
#include <bits/stdc++.h>
#define MAXN 1000005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()   srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;
int n, m;
int a[MAXN + 2], b[MAXN + 2]

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  
  for (int i = 0; i < m; i++) {
    int x, y, t; cin >> x >> y >> t;
    int xd = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] == b[j] && x <= b[j] && b[j] <= y) {
        xd += 1;
        continue;
      }

      int tt = t % (2 * (b[j] - a[j]));
      int xz = tt < b[j] - a[j] ? a[j] + tt : b[j] - (tt - (b[j] - a[j]));
      if(x <= xz && z <= y) xd += 1;
    }
    cout << xd << endl;
  }
}
