class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxi=INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                long long g = gcd(nums[i], nums[j]);

                long long value = (1LL * nums[i] * nums[j]) / (g * g);

                maxi = max(maxi, value);
            }
            
        }
        return maxi;
    }
};