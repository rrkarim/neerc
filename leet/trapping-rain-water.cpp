class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        int d[n + 2];
        memset(d, 0, sizeof d);
        for(int i = 0; i < n; ++i) {
            if(d[i]) continue;
            int j, c = 0;
            for(j = i - 1; j >= 0; --j) {
                if(height[j] > height[i]) {c = 1; break; }
            }
            int m = height[i];
            if(c == 1) {
                for(int z = i - 1; z >= j + 1; --z) {
                    d[z] = max(m, d[z]);
                }
            }
            c = 0;
            for(j = i + 1; j < n; ++j) {
                if(height[j] >= height[i]) {
                    c = 1;
                    break;
                }
            }
            m = height[i];
            if(c == 1) {
                for(int z = i + 1; z < j; ++z) {
                    d[z] = m;
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if(d[i] < height[i]) continue;
            res += d[i] - height[i];
        }
        return res;
    }
};