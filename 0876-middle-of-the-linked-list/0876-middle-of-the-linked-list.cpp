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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp= head;
        int count=0;
        while (temp != NULL){
            count++;
            temp=temp->next;
        }
        int index=count/2;
        ListNode *indexMid= head;
        for (int i=1; i<=index; i++){
            indexMid= indexMid->next;
        }
        return indexMid;
    }
};