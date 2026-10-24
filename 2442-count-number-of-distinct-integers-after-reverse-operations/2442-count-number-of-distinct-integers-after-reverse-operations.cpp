class Solution {
public:
    int reverse(int p){
        int rev=0;
        while (p!= 0){
            int dig= p%10;
            rev= rev* 10 + dig;
            p = p/10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> ans;
        for (int i=0 ; i<n; i++){
            ans.insert(nums[i]);
            ans.insert(reverse (nums[i]));
        }
        return ans.size();
    }
};