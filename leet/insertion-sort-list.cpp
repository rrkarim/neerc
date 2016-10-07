/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* curr = head->next;
        ListNode* last = head;
        if(curr == NULL) return head;
        while(curr) {
            ListNode* nx = curr->next;
            ListNode *temp = head, *pre = NULL;
            int found = 0;
            while(temp != curr) {
                if(temp->val > curr->val) {
                    found = 1;
                    break;
                }
                pre = temp;
                temp = temp->next;
            }
            if(found == 0) {
                last = curr;
                curr = nx;
                continue;
            }
            if(pre == NULL) {
                head = curr;
                curr->next = temp;
                last->next = nx;
            }
            else {
                pre->next = curr;
                curr->next = temp;
                last->next = nx;
            }
            curr = nx;
        }
        return head;
    }
};