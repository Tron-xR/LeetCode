class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        int option1=nums[0]*nums[1]*nums[2];
        int option2=nums[0]*nums[n-1]*nums[n-2];
        return max(option1,option2);
    }
};