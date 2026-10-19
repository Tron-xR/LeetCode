class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> countMap;
        
        for (int num : nums1) {
            countMap[num]++;
        }
        
        vector<int> ans;
        for (int num : nums2) {
            if (countMap[num] > 0) {
                ans.push_back(num);
                countMap[num]--;
            }
        }
        
        return ans;
    }
};