class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(*max_element(nums.begin(),nums.end())>=(nums[0]+nums[1]+nums[2]-*max_element(nums.begin(),nums.end()))) return "none";
        if(nums[0]==nums[1]&&nums[1]==nums[2]) return "equilateral";
        else if(nums[0]==nums[1]||nums[1]==nums[2]||nums[2]==nums[0]) return "isosceles";
        else return "scalene";
    }
};