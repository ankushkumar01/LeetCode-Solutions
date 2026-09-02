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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }

        temp = head;
        if (count <= k) {
            for (int i = 0; i < k; i++) {
                result[i] = temp;
                if (temp != nullptr){ 
                    ListNode* newtemp = temp->next;
                    temp->next = nullptr;
                    temp= newtemp;
                }
            }
        }
        else{
            int size = count / k;
            int rem = count % k;
            for (int i=0; i<rem; i++){
                int len =1;
                result[i] = temp;
                while ( len != size + 1){
                    len++;
                    temp = temp->next;
                }
                ListNode* newtemp = temp->next;
                temp->next = nullptr;
                temp= newtemp;
            }

            for ( int i=rem; i<k; i++ ){
                int len =1;
                result[i] = temp;
                while ( len != size){
                    len++;
                    temp = temp->next;
                }
                if (temp != nullptr){ 
                    ListNode* newtemp = temp->next;
                    temp->next = nullptr;
                    temp= newtemp;
                }
            }
        }
        return result;
    }
};