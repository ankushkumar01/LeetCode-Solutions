class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int row= nums.size();
        int col= nums[0].size();
        int max=0;
        for (int i=0; i<row; i++){
            int count=0;
            for (int j=2; j<= sqrt(nums[i][i]); j++){
                if ( nums[i][i]%j==0) {
                    count++;
                    break;
                }
            }
            if (count==0) {
                if (nums[i][i]>max && nums[i][i]!=1) max=nums[i][i];
            }

            count=0;
            for (int j=2; j<= sqrt(nums[i][col-i-1]); j++){
                if ( nums[i][col-i-1]%j==0) {
                    count++;
                    break;
                }
            }
            if (count==0) {
                if (nums[i][col-i-1]>max && nums[i][col-i-1]!=1) max=nums[i][col-i-1];
            }
        }
        return max;
    }
};