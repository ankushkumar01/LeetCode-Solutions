class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newhead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* c = new ListNode (0);
        ListNode* temp= head;
        ListNode* temp1= c;
        while ( temp != nullptr){
            ListNode* node = new ListNode (temp->val);
            temp1->next= node;
            temp= temp->next;
            temp1 = temp1->next;
        }
        c=c->next;
        
        ListNode* rev = reverse(c);
        while (head) {
            if ( head->val != rev->val ){
                return false;
            }
            head= head->next;
            rev=rev->next;
        }
        return true;
    }
};