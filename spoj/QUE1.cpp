#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;

int used[MAXN + 2];
pair <int, int> a[MAXN + 2];


int main() {
    int t, n; cin >> t;
    for(int i = 0; i < t; ++i) {
        root = NULL;
        kz = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", &a[i].first);
        for(int i = 0; i < n; ++i) scanf("%d", &a[i].second);
        sort(a, a + n);

        for(int i = 0; i < n; ++i) {
            int gl = a[i].second;
            for(int j = 0; j < n; ++j) {

                if(gl == 0 && !used[j]) {
                    used[j] = a[i].first;
                    break;
                }

                if(!used[j]) gl -= 1;

            }

        }
        for(int i = 0; i < n; ++i) printf("%d ", used[i]);
        printf("\n");
        memset(used, 0, sizeof used);
    }
}
