class Solution {
public:
    long long minOperations(vector<int>& nums,vector<int>& locked, int k) {
        int n = nums.size();
        vector<int> bit(n + 1, 0);

        auto update = [&](int i) {
            while (i <= n) {
                bit[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int sum = 0;
            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }
            return sum;
        };

        long long inversions = 0;

        for (int i = n - 1; i >= 0; i--) {
            inversions += query(nums[i] - 1);
            update(nums[i]);
        }
        vector<int> pref(n);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }

        vector<int> suff(n);
        suff[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = min(suff[i + 1], nums[i]);
        }
        vector<bool> required(n, false);

        for (int i = 0; i < n - 1; i++) {
            if (pref[i] > suff[i + 1]) {
                required[i] = true;
                required[i + 1] = true;
            }
        }

        int unlocks = 0;

        for (int i = 0; i < n; i++) {
            if (required[i] && locked[i] == 1) {
                unlocks++;
            }
        }

        if (unlocks > k) {
            return -1;
        }

        return inversions + unlocks;
    }
};
