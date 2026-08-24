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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp1= head;
        int len=1;
        if (temp1== nullptr) return nullptr;
        while (temp1->next != nullptr){
            len++;
            temp1= temp1->next;
        }
        if (k>=len){
            k=k%len;
        }
        ListNode * temp2=head;
        for (int i=1; i<len-k; i++){
            temp2=temp2->next;
        }
        temp1->next=head;
        head = temp2->next;
        temp2->next= nullptr;
        
        return head;
    }
};