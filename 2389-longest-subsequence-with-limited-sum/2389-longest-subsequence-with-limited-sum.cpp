class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m= queries.size();
        vector <int> ans (m,0);
        sort(nums.begin(), nums.end());
        for (int i=0;i<m;i++){
            int sum=0;
            for (int j=0; j<n; j++){
                sum+=nums[j];
                if ((queries[i]-sum)<0){
                    ans[i]=j;
                    break;
                }
                if (j==(n-1)){
                    ans[i]=n;
                }
            }
        }
        return ans;
    }
};