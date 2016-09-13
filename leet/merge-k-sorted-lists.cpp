/**
 * Merge k Sorted Lists
 * Complexity O(NlogN), N - number of all elements in all lists
 * We can do better: O(NlogM), M - numbers of lists 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = NULL, *ret_curr = NULL;
        if(lists.size() == 0) return ret;
        vector <int> r;
        for(int i = 0; i < lists.size(); ++i) {
            ListNode *curr = lists[i];
            while(curr) {
                r.push_back(curr->val);
                curr = curr->next;
            }
        }
        sort(r.begin(), r.end());
        for(int i = 0; i < r.size(); ++i) {
            if(ret == NULL) {
                ret = new ListNode(r[i]);
                ret_curr = ret;
            }
            else {
                ret_curr->next = new ListNode(r[i]);
                ret_curr = ret_curr->next;
            }
        }
        return ret;
    }
};