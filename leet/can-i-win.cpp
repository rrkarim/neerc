class Solution {
public:
    #ifndef mx
    #define mx 1048580
    #endif
    int mp[mx];
    int f(int n, int curr, const int &maxn) {
        if(n <= 0) return false;
        int &mp_val = mp[curr], mask = 1; 
        if(mp_val != -1) return mp_val;
        for(int i = 0; i < maxn; ++i) {
            if(!(curr & mask)) {
                curr |= mask;
                if(!f(n - i - 1, curr, maxn)) {
                    curr = (curr & (~mask));
                    return (mp_val = 1);
                }
                curr = (curr & (~mask));
            }
            mask <<= 1;
        }
        return (mp_val = 0);
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger*(maxChoosableInteger+1) / 2 < desiredTotal) return false;
        if(desiredTotal == 0) return 1;
        for(int i = 0; i < mx; ++i) mp[i] = -1;
        int c = f(desiredTotal, 0, maxChoosableInteger);
        return (c == 1 ? 1 : 0);
    }
};