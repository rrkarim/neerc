#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 300005
#define INF 10000000000000
using namespace std;

typedef long long ll;
int n, x, y, s, f, t, used[MAXN + 2];
queue <pair <int, int>> main_;
queue <int> ar[MAXN + 2];
int main() {
    int n, q, sum = 0, nz = 0;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < q; ++i) {
        scanf("%d%d", &t, &x);
        x -= 1;
        if(t == 1) {
            sum += 1;
            ar[x].push(nz), main_.push({nz++, x});
        }
        else if(t == 2) {
            sum -= ar[x].size();
            while(!ar[x].empty()) {
                int xs = ar[x].front();
                used[xs] = 1;
                ar[x].pop();
            }
        }
        else {
            while(!main_.empty() && x >= main_.front().first) {
                int i = main_.front().first,
                    xs = main_.front().second;
                    main_.pop();
                    if(!used[i]) {
                        used[i] = 1;
                        ar[xs].pop();
                        sum -= 1;
                    }
            }
        }
        printf("%d\n", sum);
    }
}
