class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector <int> suffix (n,0), prefix(n,0) ,ans;
        prefix[0]=1;
        int p=nums[0];
        for (int i=1; i<n; i++){
            prefix[i]=p;
            p*=nums[i];
        }

        suffix[n-1]=1;
        p=nums[n-1];
        for (int i=n-2; i>=0; i--){
            suffix[i]=p;
            p*= nums[i];
        }

        for (int i=0; i<n; i++){
            ans.push_back(prefix[i]* suffix[i]);
        }
        return ans;
         
    }
};