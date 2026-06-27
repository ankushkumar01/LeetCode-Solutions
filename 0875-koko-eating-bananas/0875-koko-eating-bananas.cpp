class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int maxspeed= 0;
        for (int i=0;i<n;i++){
            if (piles[i] > maxspeed) maxspeed= piles[i];
        }
        
        long long low= 1;
        long long high= maxspeed;
        long long ans= maxspeed;
        while(low<=high){
            long long mid = low +(high-low)/2;
            long long count=0;
            for (long long ele : piles){
                if (ele<=mid){
                    count++;
                }
                else{
                    long long val= ele/mid;
                    if (ele%mid==0) count+=val;
                    else count+=(val+1);
                }
            }
            if (count<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};