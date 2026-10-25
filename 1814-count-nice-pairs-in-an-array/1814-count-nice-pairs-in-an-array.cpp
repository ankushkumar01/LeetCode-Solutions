
class Solution {
public:
    int reverse(int p) {
        int rev = 0;

        while (p != 0) {
            int dig = p % 10;
            rev = rev * 10 + dig;
            p = p / 10;
        }

        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i] - reverse(nums[i])]++;
        }

        long long count = 0;

        for (auto i : m) {
            long long k = i.second;
            count = (count + k * (k - 1) / 2) % MOD;
        }

        return count;
    }
};
