class Solution {
public:
    bool great_one(vector<int> nums1, int i, vector<int> nums2, int j) {
        for(; i < nums1.size() && j < nums2.size(); ++i, ++j) {
            if(nums1[i] > nums2[j]) return 1;
            else if(nums1[i] < nums2[j]) return 0;
        }
        return i != nums1.size();
    }
    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> r;
        if(k == 0) return r;
        int i = 0, j = 0;
        for(int l = 0; l < k; ++l) {
            r.push_back(great_one(nums1, i, nums2, j) ? nums1[i++] : nums2[j++]);
        }
        return r;
    }
    vector<int> getMax(vector<int> &nums, int k) {
        vector<int> r(k);
        if(k == 0) return r;
        int i = 0;
        for(int j = 0; j < nums.size(); ++j) {
            while(nums.size() - j + i > k && i > 0 && r[i-1] < nums[j])
                i--;
            if (i < k)
                r[i++] = nums[j];
        }
        for(int i = 0; i < r.size(); ++i) cout << r[i] << " "; cout << endl;
        return r;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> r;
        if(k == 0) return r;
        int m = nums1.size(), n = nums2.size();
        if(m + n == k) {
            return merge(nums1, nums2, k); 
        }
        else {
            int max = m >= k ? k : m;
            int min = n >= k ? 0 : k - n;
            for(int i = 0; i < k; ++i) r.push_back(-1);
            for(int i = min; i <= max; ++i) {
                vector<int> temp = merge(getMax(nums1, i), getMax(nums2, k - i), k);
                r = great_one(r, 0, temp, 0) ? r : temp;
            }
            return r;
        }
    }
};