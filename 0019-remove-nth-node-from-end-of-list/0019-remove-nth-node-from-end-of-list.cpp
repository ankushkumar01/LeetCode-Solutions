
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head;
        ListNode *fast=head;

        for (int i=1; i<=n+1; i++){
            if(fast==nullptr)return head->next;
            fast=fast->next;
        }

        while(fast != nullptr){
            fast=fast->next;
            slow=slow->next;
        }

        slow->next= slow->next->next;
        return head;



        // ListNode* temp= head;
        // int len=0;
        // while (temp != nullptr){
        //     len++;
        //     temp=temp->next;
        // }

        // if (len == n){
        //     head= head->next;
        //     return head;
        // }
        // else{
        //     temp=head;
        //     for (int i=1; i<len-n; i++){
        //         temp=temp->next;
        //     }
        //     temp->next=temp->next->next;
        //     return head;
        // }
    }
};