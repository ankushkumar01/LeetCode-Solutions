class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen= s.length();
        int tlen= t.length();
        if (slen != tlen) return false;
        unordered_map<char, int> map;
        for (int i=0; i< slen ; i++){
            map[s[i]]++;
        }
        for (int j=0; j< tlen ; j++){
            if (map.find(t[j]) != map.end()){
                map[t[j]]--;
                if (map[t[j]] ==0){
                    map.erase(t[j]);
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};