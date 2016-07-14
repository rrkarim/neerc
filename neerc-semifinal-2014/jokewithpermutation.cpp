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

int d[55];
string s;
vector<int> ans;
int len(int x) {
  int len = 0
  while(x) {
    len += 1, x /= 10;
  }
  return len;
}
void init() {
  int sum = 0;
  for(int i = 1; i <= 55; ++i) {
    sum += len(i);
    d[i] = sum;
  }
}

void f() {

}

int main() {
  cin >> s;
  init();

}