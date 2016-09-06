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
    TreeNode* first = NULL, *second = NULL;
    void inorder(TreeNode* n, TreeNode* pre) {
            if(n == NULL) return;
            
            inorder(n->left, n);
            cout << n->val << " " << endl;
            if(pre != NULL) {
                cout << n->val << " " << pre->val << endl;
                if(n->val < pre->val) {
                    if(first == NULL) { 
                        first = pre;
                    }
                    second = n;
                }
            }
            inorder(n->right, n);
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        inorder(root, NULL);
        swap(first->val, second->val);
        
    }
};