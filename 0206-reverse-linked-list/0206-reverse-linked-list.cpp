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
    ListNode* reverseList(ListNode* head) {
        //Recursive 
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next=head;
        head->next= nullptr;
        return newHead;
        // Iterative
        // ListNode* prev = nullptr;
        // ListNode* curr = head;
        // ListNode* Nex = head;
        // while ( curr != nullptr){//while(curr){}
        //     Nex =curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = Nex;
        // }
        // return prev;
    }
};