/**
    Sliding Window Maximum
    O(n)
    Deque solution
    On each element - remove elements that are smaller than current and add current top the back;
    deque_front is the answer on each iteration.
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> r;
        deque<int> dq;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i - k + 1 >= 0) r.push_back(nums[dq.front()]); 
        }
        return r;
    }
};