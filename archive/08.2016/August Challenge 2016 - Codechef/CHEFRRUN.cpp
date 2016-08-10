#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
using namespace std;

typedef long long ll;
int n, x, y;
ll a[MAXN + 2]; int used[MAXN + 2];
int main() {
    int t; scanf("%d", &t);
    assert(t >= 0);
    while(t -- ) {
        int res = 0;
        //memset(used,0,sizeof used);
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%lld", a + i);
        int index = -1, k = 0;
        for(int i = 0; i < n; ++i) {
            if(used[i]) continue;
            index = i;
            int ind = index, pre = -1, fs = k;
            while(!used[ind]) {
                used[ind] = k++;
                int z = ind;
                pre = ind;
                ind = ( ind + a[ind] + 1 ) % n;
            }
            if(used[ind] >= fs) res += used[pre] - used[ind] + 1;
        }
        for(int i = 0; i < n; ++i) used[i] = 0; //memset
        printf("%d\n", res);
    }

}
