class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n= satisfaction.size();
        sort( satisfaction.begin(),satisfaction.end());
        int pos=0, neg=0, negIdx, ans=0;
        for (int i=0; i<n; i++){
            if (satisfaction[i]>=0){
                pos+= satisfaction[i];
            }
            else{
                neg+= satisfaction[i];
                negIdx=i;
            }
        }
        if (pos==0) return ans;

        int negsum=0, rIdx=0;
        for (int i=negIdx; i>=0; i--){
            negsum+=satisfaction[i];
            if ((pos+ negsum)<=0) {
                rIdx=i+1;
                break;
            }
        }

        int time=1;
        for (int i= rIdx; i<n; i++){
            ans+=time*satisfaction[i];
            time++;
        }
        return ans;
    }
};