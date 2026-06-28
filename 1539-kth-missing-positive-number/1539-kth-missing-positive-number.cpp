class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        int maxValue=0;
        for (int i=0;i<n;i++){
            if ( arr[i]> maxValue) maxValue=arr[i];
        }
        maxValue+=k;
        int count=0;
        for (int j=1,i=0;j<=maxValue && i<n;){
            if ( arr[i]==j){
                if (i==n-1) j++;
                else{
                    i++;
                    j++;
                }  
            }
            else if (j < arr[i]){
                count++;
                if (count == k){
                    return j;
                }
                j++;
            }
            else {
                count++;
                if (count == k){
                    return j;
                }
                j++;
            }
        }
        return -1;
    }
};