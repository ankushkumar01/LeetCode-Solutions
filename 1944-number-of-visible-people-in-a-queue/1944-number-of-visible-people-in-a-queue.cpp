class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n);
        stack<int> st;
        result[n-1]=0;
        st.push(heights[n-1]);
        for (int i=n-2; i>=0; i--) {
            int count=0;
            while (!st.empty() && st.top()< heights[i]){
                st.pop();
                count++;
            }
            if (!st.empty()){
                count++;
            }
            result[i]=count;
            st.push(heights[i]);
        }
        return result;
    }
};