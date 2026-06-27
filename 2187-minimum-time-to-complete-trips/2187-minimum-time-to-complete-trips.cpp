class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n= time.size();
        long long low=1;
        long long val= LLONG_MAX;
        for (int i=0; i<n;i++){
            if (time[i]< val) val=time[i];
        }
        long long high=val*totalTrips;
        long long ans=high;
        while (low<= high){
            long long  mid= low + (high - low)/2;
            long long sum=0;
            for (int i=0; i<n;i++){
                long long div=mid/time[i];
                sum+=div;
            }
            if (sum >= totalTrips){
                ans= mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};