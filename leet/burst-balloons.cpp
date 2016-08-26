/*
    DP solution
    O(n^3)
    Iterate through all substring starting from 2.
*/
int maxCoins(vector<int>& nums) {
    int numsi[nums.size() + 2];
    int n = 1;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] > 0) numsi[n++] = nums[i];
    }
    numsi[0] = numsi[n++] = 1;

    int dp[n][n] = {};
    for(int k = 2; k < n; ++k) {
        for(int left = 0; left < n - k; ++left) {
            int right = left + k;
            for(int i = left + 1; i < right; ++i) {
                dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + numsi[i] * numsi[left] * numsi[right]);
            }
        }
    }
    return dp[0][n - 1];
}