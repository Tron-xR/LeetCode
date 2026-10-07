class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        long long total = 0;
        long long firstHalf = 0;

        for (int x : nums)
            total += x;

        for (int i = 0; i < half; i++)
            firstHalf += nums[i];

        int ans = 0;

        for (int start = 0; start < n; start++) {
            if (2 * firstHalf > total)
                ans++;
            firstHalf -= nums[start];
            firstHalf += nums[(start + half) % n];
        }

        return ans;
    }
};