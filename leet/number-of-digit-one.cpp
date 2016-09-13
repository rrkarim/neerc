/*
    Number of Digit One
*/
class Solution {
public:
    typedef long long ll;
    ll d[20], sum_[20], x[20], n;
    void _init_() {
        d[1] = 1, sum_[1] = 1, x[1] = 10, x[0] = 1;
        ll t = 1;
        for(int i = 2; i <= 18; ++i) {
            d[i] = (9 * i + 1) * t, t *= 10;
            x[i] = t * 10;
            sum_[i] = sum_[i - 1] + d[i];
        }
    }
    string solve(ll n) {
        vector <int> res;
        ll sum = 0, z = 0;
        int len = -1;
        for(int i = 1; i <= n; ++i) {
            sum += d[i];
            if(sum >= n) {
                len = i;
                break;
            }
        }
        for(int i = 0; i < len; ++i) {
            ll sum_t = 0, pre_t = 0;
            for(int j = 0; j <= 9; ++j) {
                if(j == 1) sum_t += sum_[len - i - 1] + x[len - i - 1] + z * x[len - i - 1] ;
                else   sum_t += sum_[len - i - 1] + z * x[len - i - 1];
                if(sum_t >= n) {
                    n -= pre_t;
                    res.push_back(j);
                    if(j == 1) z += 1;
                    break;
                }
                pre_t = sum_t;
            }
        }
        string r;
        for(int i = 0; i < res.size(); ++i) r += ('0' + res[i]);
        return r;
    }
    bool check(int n) {
        while(n) {
            if(n % 10 == 1) return 1;
            n /= 10;
        } return 0;
    }
    int countDigitOne(int n) {
        if(n <= 0) return 0;   
        while(true) {
            if(check(n)) break;
            n -= 1;
        }
        _init_();
        ll l = 1, r = (1ll << 32);
        while(l <= r) {
            if(l == r - 1 || l == r) break;
            ll m = (l + r) / 2;
            string t = solve(m);
            ll ks = stol(t);
            if(ks == n) {
                while(true) {
                    m += 1;
                    string t = solve(m);
                    ll ks = stol(t);
                    if(ks != n) break;
                }
                m -= 1;
                return m;
            }
            else if(ks <= n) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        string t = solve(l);
        ll ks = stol(t);
        if(ks != n) return r;
        return l;
    }
};