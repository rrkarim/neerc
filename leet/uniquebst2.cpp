/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector <TreeNode*> f(int l, int r, int m) {
        vector <TreeNode*> ld, rd, res;
        if(l >= r) {
            res.push_back(new TreeNode(m));
            return res;
        }
        for(int i = l; i <= m - 1; ++i) {
            vector <TreeNode*> temp = f(l, m - 1, i);
            ld.insert(ld.end(), temp.begin(), temp.end());
        }
        if(ld.empty()) ld.push_back(NULL);
    
        for(int i = m + 1; i <= r; ++i) {
            vector <TreeNode*> temp = f(m + 1, r, i);
            rd.insert(rd.end(), temp.begin(), temp.end());
    //        if(m == 1) cout << rd.size() << endl;
        }
        if(rd.empty()) rd.push_back(NULL);
    
        for(int i = 0; i < ld.size(); ++i) {
            for(int j = 0; j < rd.size(); ++j) {
                TreeNode *temp = new TreeNode(m);
                temp->left = ld[i];
                temp->right = rd[j];
                res.push_back(temp);
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector <TreeNode*> r;
        if(n == 0) return r;
        for(int i = 1; i <= n; ++i) {
            vector <TreeNode*> temp = f(1, n, i);
            r.insert(r.end(), temp.begin(), temp.end());
        }
        return r;
    
    }
};