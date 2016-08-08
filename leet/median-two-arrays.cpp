/**
    #4 - Median of Two Sorted Arrays
*/
class Solution {
public:
    
    int f(vector<int>& nums1, vector<int>& nums2, int k, int as, int ae, int bs, int be) {
        
        int alen = ae - as + 1;
        int blen = be - bs + 1;
        
        if(alen == 0) {
            return nums2[bs + k];
        }
        else if(blen == 0) {
            return nums1[as + k];
        }
        if(k == 0) {
            return min(nums1[as], nums2[bs]);
        }
        
        int amid = alen * k / (alen + blen);
        int bmid = k - amid - 1;
        
        amid += as;
        bmid += bs;
        
        if(nums1[amid] > nums2[bmid]) {
            k -= (bmid - bs + 1);
            ae = amid;
            bs = bmid + 1;
        }
        else {
            k -= (amid - as + 1);
            be = bmid;
            as = amid + 1;
        }
        return f(nums1, nums2, k, as, ae, bs, be);
        
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if( (n + m) % 2 ) {
            return f(nums1, nums2, (n + m) / 2, 0, n - 1, 0, m - 1);
        }
        else {
            return ( f(nums1, nums2, (n + m) / 2, 0, n - 1, 0, m - 1) + f(nums1, nums2, (n + m) / 2 - 1, 0, n - 1, 0, m - 1) ) * 0.5;
        }
    }
};