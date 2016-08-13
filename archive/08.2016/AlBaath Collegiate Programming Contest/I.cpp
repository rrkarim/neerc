#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 10005
#define INF 10000000000000
using namespace std;

typedef long long ll;
const int N = 105;
int n, a[MAXN + 2];
int num[MAXN*100 + 2];
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(num,0,sizeof num);
    scanf("%d", &n);
    int res = 0;
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]), num[a[i]] += 1;
    sort(a, a + n);
    for(int i = 0; i < n; ++i) {
        int x = 0;
        for(int j = a[i]; j <= 1000000; j += a[i]) {
            if(a[i] == j) x += num[j] - 1;
            else x += num[j];
        }
        x *= num[a[i]];
        x -= num[a[i]] * (num[a[i]]-1)/2;
        res += x;
        i += num[a[i]] - 1;
        num[a[i]] = 0;
    }
    printf("%d\n", res);
  }
  return 0;
}
