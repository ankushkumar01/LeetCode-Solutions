
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* c= new ListNode (0);
        ListNode* temp = c;
        while( a != nullptr && b != nullptr ){
            if (a->val< b->val){
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }
            else{
                temp->next = b;
                b = b ->next;
                temp = temp->next;
            }
        }
        if (b == nullptr){
            temp->next = a;
        }
        else{
            temp->next = b;
        }
        return c->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = nullptr;
        a = sortList(a);
        b = sortList(b);
        ListNode* c = merge(a,b);
        return c;
    }
};