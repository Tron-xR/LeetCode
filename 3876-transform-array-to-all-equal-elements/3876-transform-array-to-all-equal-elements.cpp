class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        
        int count_neg = 0;
        for (int x : nums) {
            if (x == -1) count_neg++;
        }
        int count_pos = n - count_neg;

        if (count_neg % 2 == 0) {
            int current_neg_prefix = 0;
            int ops_needed = 0;
            for (int j = 0; j < n - 1; ++j) {
                if (nums[j] == -1) current_neg_prefix++;
                if (current_neg_prefix % 2 != 0) {
                    ops_needed++;
                }
            }
            if (ops_needed <= k) return true;
        }

        if (count_pos % 2 == 0) {
            int current_pos_prefix = 0;
            int ops_needed = 0;
            for (int j = 0; j < n - 1; ++j) {
                if (nums[j] == 1) current_pos_prefix++;
                if (current_pos_prefix % 2 != 0) {
                    ops_needed++;
                }
            }
            if (ops_needed <= k) return true;
        }

        return false;
    }
};