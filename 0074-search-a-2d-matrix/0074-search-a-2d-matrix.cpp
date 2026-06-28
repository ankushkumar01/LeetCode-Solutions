class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size(), col= matrix[0].size();
        int len=row*col;
        int low=0;
        int high= len-1;
        while (low<=high){
            int mid= low + (high-low)/2;
            int cr=mid/col;
            int cc=mid%col;
            if (matrix[cr][cc]==target) return true;
            else if  ( matrix[cr][cc]<target) low= mid+1;
            else high= mid-1;
        }
        return false;
    }
};