/**
    Topological-sort solution
    O(n^2*m^2)
*/
class Solution {
public:
vector <pair<int,int>> ans;
    int n, m;
    int x_[5] = {1, -1, 0, 0};
    int y_[5] = {0, 0, 1, -1};
    vector <vector <int>> used;
    vector <vector <int>> ind;
    bool check(int a, int b) {
        int x1 = a % m, y1 = a / m;
        int x2 = b % m, y2 = b / m;
        int s1 = abs(x1 - x2);
        int s2 = abs(y1 - y2);
        if(!s1 && s2 == 1) return 1;
        if(!s2 && s1 == 1) return 1;
        return 0;
    }
    // topological sort
    void dfs (int x, int y, vector<vector<int>>& matrix) {
     	used[x][y] = true;
    	for(int i = 0; i < 4; ++i) {
    	    int x_t = x + x_[i];
    	    int y_t = y + y_[i];
    	    if(x_t < 0 || y_t < 0 || x_t >= n || y_t >= m || used[x_t][y_t]) continue;

    	    if(matrix[x_t][y_t] > matrix[x][y]) dfs(x_t, y_t, matrix);
    	}
    	ans.push_back({matrix[x][y], ind[x][y]});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(!n) return 0;
        m = matrix[0].size();
        used.resize(n + 1);
        ind.resize(n + 1);
        for(int i = 0; i < n; ++i) used[i].resize(m + 1), ind[i].resize(m + 1);
        int k = 0;
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) ind[i][j] = k++;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(used[i][j]) continue;
                dfs(i, j, matrix);
            }
        }
        reverse(ans.begin(), ans.end());
        vector <int> d(ans.size() + 1, 0);   
        int res = 1;
        d[0] = 1;
        cout << ans.size() << endl;
        for(int i = 1; i < ans.size(); ++i) {
            int maxn = 0;
            for(int j = 0; j < i; ++j) {
                if(ans[j].first < ans[i].first && check(ans[i].second, ans[j].second)) {
                    maxn = max(maxn, d[j]);
                }
            }
            d[i] = maxn + 1;
            res = max(res, d[i]);
        }
        return res;
    }
};

/*
    Memoization method
    O(n*m)
*/

    int dx[5] = { 1 , -1, 0 , 0  };
    int dy[5] = { 0 , 0 , 1 , -1 };

    int dfs(int x, int y, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dis) {
        if (dis[x][y] != 0) return dis[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] > matrix[x][y]) {
                dis[x][y] = max(dis[x][y], dfs(nx, ny, m, n, matrix, dis));
            }
        }
        return ++dis[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector <vector <int>> dis;
        dis.resize(m + 1);
        for(int i = 0; i < dis.size(); ++i) dis[i].resize(n + 1);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs( i, j, m, n, matrix, dis));
            }
        }
        return ans;
    }
