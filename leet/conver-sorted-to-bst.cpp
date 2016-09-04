/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int len = 0;
    vector <int> vi;
    
    void add(int l, int r, TreeNode*& node) {
        
        if(l > r) return;
        
        if(l == r) {
            node = new TreeNode(vi[l]);
            return;
        }
        
        int m = (l + r) / 2;
        node = new TreeNode(vi[m]);
        add(l, m - 1, node->left);
        add(m + 1, r, node->right);
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            vi.push_back(curr->val);
            curr = curr->next;
            len += 1;
        }
        TreeNode* ret;
        add(0, len - 1, ret);
        return ret;
    }
};