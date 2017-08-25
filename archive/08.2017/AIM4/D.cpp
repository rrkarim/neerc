#include <bits/stdc++.h>
#include <string>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 100004

using namespace std;
#define fir first
#define sec second
#define pb push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

const ll mod = 1e9 + 7ll;
int n, start, x, val, next_, a, b, c, d;

void query(const int& i) {
        printf("? %d\n", i);
        fflush(stdout);
        scanf("%d%d", &val, &next_);
}

int main() {
        srand(time(NULL));
        int x = rand();
        scanf("%d%d%d", &n, &start, &x);
        for(int i = 0; i < 999; ++i) {
            query( (1ll * (rand() * rand()) % n + 1 ) );
            c = val, d = next_;
            if(c < x && c >= a) a = c, b = d;
        }
        while(a < x) {
        if(b < 0) return 0 * printf("! -1\n");
            query(b);
            a = val, b = next_;
        }
        printf("! %d\n", a);
}
