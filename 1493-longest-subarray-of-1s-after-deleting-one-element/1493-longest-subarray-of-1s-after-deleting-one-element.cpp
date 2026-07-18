class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size();
        int maxlen= INT_MIN;
        int currentlen=0;
        int i=0, j=0;
        int del=0, delInd=-1;
        while( j<n){
            if (nums[j]==1) j++;
            else {
                if (del==0){
                    delInd=j;
                    j++;
                    del++;
                }
                else{
                    currentlen=j-i-1;
                    maxlen=max(currentlen, maxlen);
                    i=delInd+1;
                    delInd=j;
                    j++;

                }
            }
        }
        currentlen=j-i-1;
        maxlen=max(currentlen, maxlen);
        return maxlen;
    }
};