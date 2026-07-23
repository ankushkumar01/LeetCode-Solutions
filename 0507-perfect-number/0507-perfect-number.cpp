class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num==1) return false;
        for (int i = 1; i <= sqrt(num); i++) {
            if ( num % i==0 ) {
                if (i==1) sum=1;
                else if (i==sqrt(num)){
                    sum+=i;
                }
                else sum+=i+ (num/i);
            }
        }
        if (sum==num) return true;
        return false;
    }
};