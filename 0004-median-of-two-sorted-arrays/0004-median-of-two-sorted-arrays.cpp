class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1= nums1.size();
        int s2= nums2.size();
        int a=s1+s2;
        
        nums1.resize(a);
        double ans;
        int i=s1-1;
        int j=s2-1;
        int k=a-1;
        while (i>=0 && j>=0 && k>=0){
            if (nums1[i]<= nums2[j]){
                nums1[k]=nums2[j];

                k--;
                j--;
            }
            else if (nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                k--;
                i--;
            }
        }
        if (j>=0 && k>=0){
            while(j>=0){
                nums1[k]=nums2[j];
                k--;
                j--;
            }
        }
        
        
        
        if (a%2==0){
            double add=(nums1[a/2] + nums1[(a/2)-1]);
            ans=(add/2);
        }
        else{
            ans=nums1[((a-1)/2)];
        }
        return ans;
        
    }
};