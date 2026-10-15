class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> elements;
            for (int j = i; j < n; j++) {
                elements.insert(nums[j]);
                int count = elements.size();
                sum += count * count;
            }
        }
        
        return sum;
    }
};