/**
 * Reverse Nodes in k-Group
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* last = NULL, *pre = NULL, *pre_last = NULL;
    void reverse(ListNode* pr, ListNode*& n, int k, int s) {
        if(s == k || n == NULL) return;
        pre = n;
        reverse(n, n->next, k, s + 1);
        if(pr) n->next = pr;
        last = n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode *root = NULL, *curr = head;
        int len = 0, index = 0;
        while(curr != NULL) len += 1, curr = curr->next;
        curr = head;
        for(int i = 0; i < len / k; i += 1) {
            ListNode* t = curr;
            for(int j = 0; j < k; ++j) curr = curr->next;
            reverse(NULL, t, k, 0);
            if(pre_last) pre_last->next = pre;
            else root = pre;
            pre_last = last;
        }
        if(len % k) {
            if(pre_last == NULL) return head;
            while(curr != NULL) {
                pre_last->next = curr;
                pre_last = pre_last->next;
                curr = curr->next;
            }
        }
        else last->next = NULL;
        return root;
    }
};