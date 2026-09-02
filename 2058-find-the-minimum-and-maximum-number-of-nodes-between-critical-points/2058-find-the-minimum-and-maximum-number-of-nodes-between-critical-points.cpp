/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        
        int first_idx = -1, last_idx = -1;
        int min_dist = INT_MAX;
        
        while (curr && curr->next) {
            ListNode* nxt = curr->next;
            if ((curr->val > prev->val && curr->val > nxt->val) ||
                (curr->val < prev->val && curr->val < nxt->val)) {
                // curr is a critical point
                if (first_idx == -1) {
                    first_idx = idx;
                } else {
                    min_dist = min(min_dist, idx - last_idx);
                }
                last_idx = idx;
            }
            
            prev = curr;
            curr = nxt;
            idx++;
        }
        
        if (first_idx == -1 || first_idx == last_idx) {
            return {-1, -1};
        }
        
        int max_dist = last_idx - first_idx;
        return {min_dist, max_dist};
    }
};