class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high= n-1;
        int pos=0;
        while(low<=high){
            int mid= low + (high-low)/2;
            if (nums[mid]<=0){
                low= mid+1;
            }
            else{
                if (mid>0 && nums[mid-1]>0) high= mid-1;
                else{
                    pos = n- mid;
                    break;
                }
            }
        }
        low=0;
        high= n-1;
        int neg=0;
        while(low<=high){
            int mid= low + (high-low)/2;
            if (nums[mid]>=0){
                high= mid-1;
            }
            else{
                if (mid<n-1 && nums[mid+1]<0){
                    low= mid+1;
                }
                else{
                    
                    neg=mid+1;
                    break;
                }
            }
        }
        if (neg> pos) return neg;
        else return pos;
    }
};