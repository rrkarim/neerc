class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i <= j) {    
            while(nums[i] == nums[j] && i != j) i += 1;
            if(nums[i] <= nums[j]) return nums[i];
            int m = (i + j) / 2;
            if(nums[m] >= nums[i]) {
                i = m + 1;
            }
            else j = m;
        }
        return -1;
    }
};