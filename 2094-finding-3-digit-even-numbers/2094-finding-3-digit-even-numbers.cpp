class Solution {
public:
    bool isPossible(int p, unordered_map<int, int> m){
        while(p >0){
            int dig= p%10;
            p=p/10;
            if (m.find(dig) != m.end()){
                m[dig]--;
                if (m[dig]==0) m.erase(dig);
            }
            else return false;
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n= digits.size();
        vector<int> ans;
        unordered_map<int, int>m;
        for (int i=0; i<n ; i++){
            m[digits[i]]++;
        }
        for (int i=100; i<1000; i++){
            if (i%2==0){
                if (isPossible(i, m)){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};