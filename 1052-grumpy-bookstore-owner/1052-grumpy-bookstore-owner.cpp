class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n= customers.size();

        int windowSum=0;
        for (int i=0; i<minutes; i++){
            if (grumpy[i]==1){
                windowSum+=customers[i];
            } 
        }

        int i=1;
        int j=i+minutes-1;
        int maxSum=windowSum, maxIdx=0;
        while (j<=n-1){
            windowSum= windowSum + (grumpy[j]==1?customers[j]:0) - (grumpy[i-1]==1?customers[i-1]:0);
            if (windowSum>maxSum) {
                maxSum=windowSum;
                maxIdx=i;
            }
            i++;
            j++;
        }

        for (i=maxIdx; i< maxIdx+minutes; i++){
            if (grumpy[i]==1) grumpy[i]=0;
        }

        int ans=0;
        for (i=0; i<n; i++){
            if (grumpy[i]==0){
                ans+= customers[i];
            }
        }
        return ans;
    }
};