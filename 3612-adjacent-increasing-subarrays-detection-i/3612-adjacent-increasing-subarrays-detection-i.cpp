class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;

        int num_windows = n - k + 1;
        vector<bool> is_inc(num_windows, false);
        int violations = 0;
        for (int j = 0; j < k - 1; ++j) {
            if (nums[j] >= nums[j + 1]) {
                violations++;
            }
        }
        is_inc[0] = (violations == 0);
        for (int i = 1; i < num_windows; ++i) {
            if (nums[i - 1] >= nums[i]) {
                violations--;
            }
            if (nums[i + k - 2] >= nums[i + k - 1]) {
                violations++;
            }
            is_inc[i] = (violations == 0);
        }
        for (int a = 0; a <= n - 2 * k; ++a) {
            if (is_inc[a] && is_inc[a + k]) {
                return true;
            }
        }

        return false;
    }
};