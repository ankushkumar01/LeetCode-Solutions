class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
          
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }

    // bool checkPrime (int p){
    //     int count=0;
    //     for (int i=2; i<= sqrt(p); i++){
    //         if (p%i==0) count++;
    //         if (count>0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // int countPrimes(int n) {
    //     if (n<=2) return 0;
    //     int count=1;
    //     for (int i=3; i<n; i+=2){
    //         if (checkPrime(i)) count++;
    //     }
    //     return count;
    // }
};