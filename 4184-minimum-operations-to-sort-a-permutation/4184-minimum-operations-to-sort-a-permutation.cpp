class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                p = i;
                break;
            }
        }

        bool is_inc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(p + i) % n] != i) {
                is_inc = false;
                break;
            }
        }

        bool is_dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(p - i + n) % n] != i) {
                is_dec = false;
                break;
            }
        }

        int min_ops = 1e9;
        if (is_inc) {
            min_ops = min(min_ops, p);
            min_ops = min(min_ops, n - p + 2);
        }
        if (is_dec) {
            min_ops = min(min_ops, ((p + 1) % n) + 1);
            min_ops = min(min_ops, n - p);    
        }

        return min_ops == 1e9 ? -1 : min_ops;
    }
};