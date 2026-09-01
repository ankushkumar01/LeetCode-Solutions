class Solution {
public:
    ListNode* reverse ( ListNode * head){
        ListNode * prev= nullptr;
        ListNode * curr= head;
        ListNode * nex = head;
        while ( curr){
            nex= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode * rev= reverse( slow->next);
        slow->next= nullptr;
        slow-> next= rev;
        slow= slow->next;

        while ( slow){
            if ( head->val != slow->val){
                return false;
            }
            head= head->next;
            slow= slow->next;
        }
        return true;
    }
};