/**
    Count of Range Sum
    Divide and Conquear solution
    O(nlognlogn)
*/
class Solution {
public:
    int res = 0;
    void rec(vector<int>& nums, int l, int r, int lower, int upper) {
        if(l == r) {
            if(nums[l] >= lower && nums[l] <= upper) res += 1;
            return;
        }
        int m = (r + l - 1) / 2;
        vector <long long>::iterator it1, it2;
        vector <long long> ld;
        ld.push_back(nums[m]);
        long long sum = nums[m];
        for(int i = m - 1; i >= l; --i) {
            sum += nums[i];
            ld.push_back(sum);
        }
        sort(ld.begin(), ld.end());
        sum = 0;
        for(int i = m + 1; i <= r; ++i) {
            sum += nums[i];
            long long x1 = lower - sum, x2 = upper - sum;
            int d1, d2;
            it2 = upper_bound(ld.begin(), ld.end(), x2);
            if(it2 != ld.begin()) {
                it2--; 
                d2 = distance(ld.begin(), it2) + 1;
            }
            else d2 = 0;
            it1 = lower_bound(ld.begin(), ld.end(), x1);
            if(it1 != ld.begin())  {
                it1--;
                d1 = distance(ld.begin(), it1) + 1;
            }
            else d1 = 0;
            
            res += d2 - d1;
        }
        rec(nums, l, m, lower, upper);
        rec(nums, m + 1, r, lower, upper);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0) return 0;
        rec(nums, 0, nums.size() - 1, lower, upper);
        return res;
    }
};