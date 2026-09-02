class Solution {
public:
    ListNode* reverseList(ListNode* header){
        ListNode* prev = nullptr;
        ListNode* curr = header;
        ListNode* nex = header;
        while (curr != nullptr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while ( fast->next != nullptr && fast->next->next != nullptr ){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = reverseList( slow->next);
        slow->next = nullptr;
        ListNode* tempNode = new ListNode (0);
        ListNode* c = tempNode;
        while (temp){
            c->next = head;
            c = c->next;
            head = head->next;
            c->next = temp;
            c = c->next;
            temp = temp->next;
        }
        c->next =head;
        head = c->next;
        delete (tempNode);
    }
};