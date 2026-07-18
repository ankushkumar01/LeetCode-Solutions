class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int flag=0;
        int maxLen= INT_MIN;
        int currLen=0;
        int i=0;
        int j=0;
        while (j<n){
            if (nums[j]==1) j++;
            else{
                if (flag < k){
                    flag++;
                    j++;
                }
                else{
                    currLen=j-i;
                    maxLen= max(currLen, maxLen);
                    while (nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
        }
        currLen = j - i;
        maxLen = max(currLen, maxLen);
        return maxLen;
    }
};