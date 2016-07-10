/**
    Rasul Kerimov (CoderINusE)
    Alter Board
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()   srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;
 
using namespace std;  
  
int n, m;  
int main() {  
    cin >> n >> m;  
    cout << n / 2 + m / 2 << endl;
    for(int i = 2;i <= n;i += 2)  
        cout << i << " " << 1 << " " << i << " " << m << endl;  
    for(int j = 2;j <= m;j += 2)  
        cout << 1 << " " << j << " " << n << " " << j << endl;
    return 0;  
}  