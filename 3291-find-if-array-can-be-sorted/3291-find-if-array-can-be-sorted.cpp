class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int prev_max = -1;
        
        while (i < n) {
            int j = i;
            int set_bits = __builtin_popcount(nums[i]);
            int curr_min = nums[i];
            int curr_max = nums[i];
            
            while (j < n && __builtin_popcount(nums[j]) == set_bits) {
                curr_min = min(curr_min, nums[j]);
                curr_max = max(curr_max, nums[j]);
                j++;
            }
            if (curr_min < prev_max) {
                return false;
            }
            
            prev_max = curr_max;
            i = j;
        }
        
        return true;
    }
};