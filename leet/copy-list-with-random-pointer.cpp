/** 
 * Copy List with Random Pointer
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map <RandomListNode*, int> mp;
    unordered_map <int, RandomListNode*> mp_;
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *ret = NULL;
        if(head == NULL) return ret;
        RandomListNode *curr = head, *ret_curr = NULL; int i = 0;
        while(curr) {
            mp[curr] = i++;
            if(ret == NULL) {
                ret = new RandomListNode(curr->label);
                ret_curr = ret;
                mp_[i-1] = ret_curr;
            }
            else {
                ret_curr->next = new RandomListNode(curr->label);
                ret_curr = ret_curr->next;
                mp_[i-1] = ret_curr;
            }
            curr = curr->next;
        }
        curr = head, ret_curr = ret;
        while(curr) {
            if(curr->random != NULL) ret_curr->random = mp_[ mp[curr->random] ];
            else ret_curr->random = NULL;
            curr = curr->next;
            ret_curr = ret_curr->next;
        }
        return ret;
    }
};