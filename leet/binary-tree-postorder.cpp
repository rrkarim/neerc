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
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> ret;
        if(root == NULL) return ret;
        map <TreeNode*, TreeNode*> M;
        TreeNode* curr = root;
        M[root] = NULL;
        while(true) {
            if(curr == NULL) break;
            if(curr->left != NULL && !M[curr->left]) {
                M[curr->left] = curr;
                curr = curr->left;
            }
            else if(curr->right != NULL && !M[curr->right]) {
                M[curr->right] = curr;
                curr = curr->right;
            }
            else {
                ret.push_back(curr->val);
                curr = M[curr];
            }
            
        }
        return ret;
    }
};