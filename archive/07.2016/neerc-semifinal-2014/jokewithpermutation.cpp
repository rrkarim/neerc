/**
    Rasul Kerimov (CoderINusE)
    Jokewithpermutation
*/
#include <bits/stdc++.h>
#define MAXN 1000005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()   srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

int ds[56], n;
string s;
vector<int> ans, used;

int len(int x) {
    int len = 0;
    while(x) len += 1, x /= 10;
    return len;
}
void init() {
    int sum = 0;
    for(int i = 1; i <= 55; ++i) {
        sum += len(i);
        ds[i] = sum;
    }
}

void f(vector<int>& v, string s, int ind, int num, vector<int>& used) {

    if(ind == s.length()) {
        if(used[num]) return;
        if(num) v.push_back(num);
        for(int i = 1; i < v.size(); ++i) cout << v[i] << " ";
        exit(0);
    }

    int temp = num;

    if(!used[num]) {
        v.push_back(num);
        used[num] = 1;
        num = (s[ind] - '0');
        f(v, s, ind + 1, num, used);
        used[temp] = 0;
        v.pop_back();
    }
    num = temp;

    num *= 10;
    num += (s[ind] - '0');
    if(n >= ds[num] && num <= 50) f(v, s, ind + 1, num, used);
}

int main() {
    cin >> s;
    used.resize(55);
    n = s.size();
    init();
    f(ans, s, 0, 0, used);
}
