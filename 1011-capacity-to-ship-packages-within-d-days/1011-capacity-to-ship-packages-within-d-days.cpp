class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int mincap = 0, maxcap = 0;

        for (int i = 0; i < n; i++) {         
            if (weights[i] > mincap)
                mincap = weights[i];
            maxcap += weights[i];
        }

        int ans = maxcap;
        while (mincap <= maxcap) {
            int mid = mincap + (maxcap - mincap) / 2;
            int count = 1, sum = 0;            
            for (int w : weights) {
                if (sum + w > mid) {
                    count++;
                    sum = 0;
                }
                sum += w;
            }

            if (count <= days) {
                ans = mid;                     
                maxcap = mid - 1;
            } else {
                mincap = mid + 1;
            }
        }
        return ans;
    }
};