class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        if (nums[0]>= n) return n;
        for (int i=1;i<=n-1;i++){
            if (nums[i]>= n-i && (n-i)>nums[i-1]){
                return n-i;
            }
        }
        return -1;
    }
};