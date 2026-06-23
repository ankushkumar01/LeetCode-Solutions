

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans (numRows);
        for (int i=0; i<numRows; i++){
            ans[i].resize(i+1);
            ans[i][0]= ans[i][i]=1;
            for (int j=1; j<=i-1; j++){
                ans[i][j]= ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;

        // for (int i=0; i<numRows; i++){
        //     int coefficient =1;
        //     for (int j=0; j<=i;j++){
        //         cout<< coefficient<<" ";
        //         coefficient=coefficient*(i-j)/(j+1);
            
        //     }
        // }
        
    }
};