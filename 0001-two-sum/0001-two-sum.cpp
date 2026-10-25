class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i=0; i< n; i++){
            int curr= nums[i];
            int rem = target - curr;
            if (m.find(rem) != m.end()){
                ans.push_back(i);
                ans.push_back(m[rem]);
                break;
            }
            else{
                m[curr]=i;
            }
        }
        return ans;
    }
};