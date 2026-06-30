class Solution {
public:
    int trap(vector<int>& height) {
        int s= height.size();
        vector <int> lower(s);
        vector <int> high(s);
        int lmax=height[0], rmax=height[s-1];
        int ans=0;
        for (int i=0,j=s-1;i<=s-1;i++,j--){
            if (i==0 && j==s-1){
                lower[i]=height[i];
                high[j]=height[j];
            }
            else{
                if (height[i]>lower[i-1]){
                    lower[i]=height[i];
                }
                else{
                    lower[i]=lower[i-1];
                }
                if (height[j]>high[j+1]){
                    high[j]=height[j];
                }
                else{
                    high[j]=high[j+1];
                }
            }
        }
        for (int i=0;i<=s-1;i++){
            ans+=min(lower[i],high[i])-height[i];
        }
        return ans;
    }
};