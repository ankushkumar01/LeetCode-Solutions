
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp= head;
        int len=0;
        while (temp != nullptr){
            len++;
            temp=temp->next;
        }

        if (len == n){
            head= head->next;
            return head;
        }
        else{
            temp=head;
            for (int i=1; i<len-n; i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            return head;
        }
    }
};