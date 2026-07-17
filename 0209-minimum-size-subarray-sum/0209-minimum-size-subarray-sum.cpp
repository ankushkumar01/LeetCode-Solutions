class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        int low=1;
        int high=n;
        while(low<=high){
            int mid= low + (high - low)/2;
            int windowSum=0;
            for (int i=0; i<mid; i++){
                windowSum+= nums[i];
            }
            int maxSum=windowSum;
            int k=1;
            int l=k+mid-1;
            while (l<=n-1){
                windowSum+= nums[l] -nums[k-1];
                if (windowSum>maxSum) maxSum=windowSum;
                k++;
                l++;
            }
            if (maxSum>= target){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};