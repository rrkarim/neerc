/*
    Jump Game 2
    Interesting solution.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int sc = 0, e = 0, maxn = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            maxn = max(maxn, i + nums[i]);
            if(i == e) {
                e = maxn;
                sc += 1;
            }
        }
        return sc;
    }
};
/*
    Jump Game
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sc = 0, e = 0, maxn = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            maxn = max(maxn, i + nums[i]);
            if(i == e) {
                e = maxn;
                sc += 1;
            }
        }
        if(e < nums.size() - 1) return 0;
        return 1;
    }
};