class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        while (i < n) {
            if (nums[i] != i + 1) {
                int correctIndex = nums[i] - 1;
                if (nums[i] == nums[correctIndex]) {
                    
                    return nums[i];
                } else {
                    swap(nums[i], nums[correctIndex]);
                }
            } else {
                i++;
            }
        }
        
        return -1; 
    }
};
