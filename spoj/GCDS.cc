#include <bits/stdc++.h>
#define INF 100000000000005
#define MAXN 10010005
#define mod 1000000007
#pragma comment(lib, "user32")
 
using namespace std;
 
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int prime[MAXN + 2], xd[100005];
char dl[MAXN + 2];
vector <int> prime_list;
 
void erat(const int& n) {
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= n; ++i)
        if (prime[i] == 0)
            if (i * 1ll * i <= n)
                for (int j = i; j <= n; j += i) {
                    prime[j] = i;
                }
 
    for(int i = 2; i <= n; ++i) {
        if(prime[i] == i || prime[i] == 0) prime_list.push_back(i);
    }
}
 
int main() {
    erat(MAXN);
    int t, n, x; scanf("%d", &t);
    for(int i = 0; i < MAXN; ++i) dl[i] = '0';
 
    for(int i = 0; i < t; ++i) {
        scanf("%d", &n);
 
        for(int j = 0; j < n; ++j) {
            scanf("%d", &xd[j]);
            int temp = xd[j];
            while(true) {
                if(prime[temp] == temp || !prime[temp]) {
                    dl[temp] = '1';
                    break;
                }
                dl[prime[temp]] = '1';
                temp = temp / prime[temp];
            }
        }
 
        for(int it : prime_list) {
            if(dl[it] == '0') {
                printf("%d\n", it);
                break;
            }
        }
 
        for(int j = 0; j < n; ++j) {
            int temp = xd[j];
            while(true) {
                if(prime[temp] == temp || !prime[temp]) {
                    dl[temp] = '0';
                    break;
                }
                dl[prime[temp]] = '0';
                temp = temp / prime[temp];
            }
        }
    }
}
 
