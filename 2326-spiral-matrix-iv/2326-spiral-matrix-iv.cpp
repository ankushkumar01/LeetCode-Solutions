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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode *temp=head;
        vector<vector<int>> result(m, vector <int> (n, -1));
        int minr=0, maxr=m-1;
        int minc=0, maxc=n-1;
        while (minr<= maxr && minc<=maxc){
            //right
            for (int i= minc; i<=maxc; i++){
                if (temp == nullptr) return result;
                result[minr][i]=temp->val;
                temp= temp->next;
            }
            minr++;
            if (minr> maxr || minc>maxc) break;
            //down
            for (int i= minr; i<=maxr; i++){
                if (temp == nullptr) return result;
                result[i][maxc]=temp->val;
                temp= temp->next;
            }
            maxc--;
            if (minr > maxr || minc > maxc) break;
            //left
             for (int i= maxc; i>=minc; i--){
                if (temp == nullptr) return result;
                result[maxr][i]=temp->val;
                temp= temp->next;
            }
            maxr--;
            if (minr> maxr || minc>maxc) break;
            //up
            for (int i= maxr; i>=minr; i--){
                if (temp == nullptr) return result;
                result[i][minc]=temp->val;
                temp= temp->next;
            }
            minc++;
            
        }
        return result;
    }
};