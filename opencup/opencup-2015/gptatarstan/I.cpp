#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c = 1000000007;

multiset <ll> S[16];
int x[5];
void add_point() {
    for(int i = 0; i < (1 << 4); ++i) {
        ll sum = 0;
        for(int j = 0; j < 4; ++j) {
            if( i & (1 << j) ) sum += x[j];
            else sum -= x[j];
        }
        S[i].insert(sum);
    }
}

void remove_point() {
    for(int i = 0; i < (1 << 4); ++i) {
        ll sum = 0;
        for(int j = 0; j < 4; ++j) {
            if( i & (1 << j) ) sum += x[j];
            else sum -= x[j];
        }
        S[i].erase(sum);
    }
}

ll distance() {
    ll distance = 0;
    for(int i = 0; i < (1 << 4); ++i) {
        ll sum = 0;
        for(int j = 0; j < 4; ++j) {
            if( i & (1 << j) ) sum += x[j];
            else sum -= x[j];
        }
        distance = max(distance, (ll)abs(sum - *(--S[i].end())));
    }
    return distance;
}

int main() {
    int n, t;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {

        scanf("%d%lld%lld%lld%lld", &t, &x[0], &x[1], &x[2], &x[3]);
        if(t == 1) add_point();
        else if(t == 2) remove_point();
        else printf("%lld\n", distance());


    }
}
