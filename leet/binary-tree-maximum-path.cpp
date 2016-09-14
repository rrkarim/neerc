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
    int find_max(TreeNode *n, int &res) {
        if(n == NULL) return 0;
        int l = find_max(n->left, res), r = find_max(n->right, res);
        int max_s = max(n->val, max(l, r) + n->val), max_t = max(max_s, l + r + n->val);
        res = max(max_t, res);
        return max_s;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int res = -100000000;
        find_max(root, res);
        return res;
    }
};