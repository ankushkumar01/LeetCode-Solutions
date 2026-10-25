class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n= words.size();
        int count=2*n;
        unordered_set<string> ans;
        for (int i=0; i<n; i++){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if (words[i] == rev){
                ans.insert(words[i]);
                count--;
            }
            else{
                ans.insert(words[i]);
                ans.insert(rev);
            }
        }
        return (count-ans.size())/2;
    }
};