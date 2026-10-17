class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> st;
        int len=students.size();
        for (int i=0; i<len; i++){
            st.push(students[i]);
        }
        int count=0;
        int i=0;
        int x;
        while(st.size()>0 && count<st.size()){
            if (st.front()== sandwiches[i]){
                i++;
                st.pop();
                count=0;
            }
            else{
                x=st.front();
                st.pop();
                st.push(x);
                count++;
            }
        }
        return st.size();
    }
};