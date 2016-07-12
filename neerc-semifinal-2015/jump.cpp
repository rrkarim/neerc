/**
    Rasul Kerimov (CoderINusE)
    Jump
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()	srand(time(NULL))
#define RANDOM(L, R)	(L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

int n, r;
char s[105], s1[105];

int quer(char st[]) {
    cout << s << endl;
    fflush(stdout);
    cin >> r;
    if(r == n) {
        exit(0);
    }
    return r;
}
int main() {
    cin >> n;
    while(true) {
        for(int i = 0; i < n; ++i) {
            s[i] = char('0' + rand() % 2);
        }
        r = quer(s);
        if(r == n / 2) {
            s1[0] = s[0];
            break;
        }
    }
    for(int i = 1; i < n; ++i) {
        s[0] ^= 1, s[i] ^= 1;
        r = quer(s);
        s1[i] = '0' + (r == n / 2);
        s[0] ^= 1, s[i] ^= 1;
        if(s[i] == '1') s1[i] ^= 1;          
    }
    cout << s1 << endl;
    r = quer(s1);
    for(int i = 0; i < n; ++i) s1[i] ^= 1;
    r = quer(s1);
}