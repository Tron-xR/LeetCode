class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            squares[i] = val * val;
        }
        
        sort(squares.begin(), squares.end());
        
        long long ans = 0;
        int m = n / 2;
        for (int i = 0; i < n; ++i) {
            if (i < m) {
                ans -= squares[i];
            } else {
                ans += squares[i];
            }
        }
        
        return ans;
        
    }
};