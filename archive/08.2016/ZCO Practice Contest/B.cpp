#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 100005
#define INF 1000000
using namespace std;
typedef long long ll;

int n, q, _index = 0, full = 0;
ll h, a[MAXN + 2];
int main() {
    cin >> n >> h;
    for(int i = 0; i < n; ++i) scanf("%lld", a + i);
    while(true) {

        scanf("%d", &q);
        if(!q) break;
        if(q == 1) {
            if(_index != 0) _index -= 1;
        }
        else if(q == 2) {
            if(_index != n - 1) _index += 1;
        }
        else if(q == 3) {
            if(!full && a[_index]) {
                full = 1;
                a[_index] -= 1;
            }
        }
        else {
            if(full && a[_index] <= h - 1) {
                a[_index] += 1;
                full = 0;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        printf("%lld ", a[i]);
}
