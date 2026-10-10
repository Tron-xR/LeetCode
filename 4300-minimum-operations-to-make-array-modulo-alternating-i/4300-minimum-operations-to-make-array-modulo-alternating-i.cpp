class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> even_cost(k, 0);
        vector<long long> odd_cost(k, 0);
        
        for (int i = 0; i < n; ++i) {
            int r = (nums[i] % k + k) % k;
            for (int target = 0; target < k; ++target) {
                int cost = min((target - r + k) % k, (r - target + k) % k);
                if (i % 2 == 0) {
                    even_cost[target] += cost;
                } else {
                    odd_cost[target] += cost;
                }
            }
        }
        
        long long min_ops = LLONG_MAX;
        
        for (int x = 0; x < k; ++x) {
            for (int y = 0; y < k; ++y) {
                if (x != y) {
                    min_ops = min(min_ops, even_cost[x] + odd_cost[y]);
                }
            }
        }
        
        return min_ops;
    }
};