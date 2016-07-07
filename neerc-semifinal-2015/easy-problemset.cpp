/**
    Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define MAXN 1000000
#define INF 2000000
#define _INF -20000000
#define RANDOM_INIT()	srand(time(NULL))
#define RANDOM(L, R)	(L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

vector <vector <int> > vi(15);
int pos[20];
int main() {
    ios_base::sync_with_stdio(0);
    int n, k, sz, t; cin >> n >> k;
    int sum = 0, ch = 0;
    for(int i = 0; i < n; ++i) {
        cin >> sz;
        for(int j = 0; j < sz; ++j) {
            cin >> t;
            vi[i].push_back(t);
        }
        pos[i] = 0;
    }
    int ind = 0;
    for(int z = 0; z < 1000; ++z) {
        if(!k) break;
        int x = (pos[ind] < vi[ind].size() ? vi[ind][pos[ind]++] : 50 );

        if(x >= sum) {
            sum += x;
            k -= 1;
        }
        ind = (ind + 1) % n;

    }

    cout << sum + k * 50 << endl;


}
