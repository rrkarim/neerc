#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 100005
#define INF 10000000000000
using namespace std;

typedef long long ll;

ll x;
vector <ll> vi;
vector <ll>::iterator it;
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        scanf("%I64d", &x);
        vi.push_back(x);
    }
    sort(vi.begin(), vi.end());
    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        scanf("%I64d", &x);
        it = upper_bound(vi.begin(), vi.end(), x);
        printf("%d\n", (int)distance(vi.begin(), it));
    }
}