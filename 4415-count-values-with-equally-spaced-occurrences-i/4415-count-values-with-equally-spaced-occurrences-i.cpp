class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> index_map;
        
        for (int i = 0; i < nums.size(); ++i) {
            index_map[nums[i]].push_back(i);
        }
        
        int cnt=0;
        
        for (const auto& [x, idx] : index_map) {
            if (idx.size() == 3) {
                if (idx[1] - idx[0] == idx[2] - idx[1]) {
                    cnt++;
                }
            }
        }
        
        return cnt;

    }
};