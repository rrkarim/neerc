class Solution {
public:
    unordered_map <int, pair<int, int>> mp;
    unordered_map <int, int> u;
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i == 0) {
                mp[nums[i]] = {nums[i],nums[i]};
                res = 1;
                u[nums[i]] = 1;
            }
            else {
                if(u[nums[i]]) continue;
                mp[nums[i]] = {nums[i],nums[i]};
                if(mp.count(nums[i] - 1)) mp[nums[i]].first = mp[nums[i] - 1].first;
                if(mp.count(nums[i] + 1)) mp[nums[i]].second = mp[nums[i] + 1].second;
                if(mp.count(nums[i] - 1)) mp[mp[nums[i] - 1].first].second = mp[nums[i]].second;
                if(mp.count(nums[i] + 1)) mp[mp[nums[i] + 1].second].first = mp[nums[i]].first;
                res = max(res, mp[nums[i]].second - mp[nums[i]].first + 1);
                u[nums[i]] = 1;
            }
        }
        return res;
    }
};