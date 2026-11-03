class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        int totalSum=0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        totalSum=nums.size()*maxi;

        return abs(sum-totalSum);
    }
};