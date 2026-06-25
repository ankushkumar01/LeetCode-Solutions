class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;

        if (x <= arr[0]) {
            for (int i = 0; i < k; i++)
                ans.push_back(arr[i]);
            return ans;
        } else if (x >= arr[n - 1]) {
            for (int i = n - k; i < n; i++)
                ans.push_back(arr[i]);
            return ans;
        }

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        int left = high;
        int right = low;

        while ((int)ans.size() < k) {
            if (left < 0) {
                ans.push_back(arr[right++]);
            } else if (right >= n) {
                ans.push_back(arr[left--]);
            } else if (x - arr[left] <= arr[right] - x) {
                ans.push_back(arr[left--]);
            } else {
                ans.push_back(arr[right++]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};