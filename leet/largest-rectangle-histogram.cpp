/*
    Largest Rectangle in Histogram
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = -1;
        if(n == 0) return 0;
        stack <int> st;
        int i = 0;
        while(i < n) {
            if(st.empty() || heights[st.top()] <= heights[i])
                st.push(i++);
            else {
                int tp = st.top();
                st.pop();
                int area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
                res = max(res, area);
            }
        }
        while(!st.empty()) {
            int tp = st.top();
            st.pop();
            int area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
            res = max(res, area);
        }
        return res;
    }
};