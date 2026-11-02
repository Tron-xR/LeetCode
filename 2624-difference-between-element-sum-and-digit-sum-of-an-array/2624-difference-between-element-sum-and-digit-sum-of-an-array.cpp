class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int el_sum=0;
        int digit_sum=0;
        vector<int> original=nums;
        for(int i=0;i<nums.size();i++)
        {
            el_sum+=original[i];
            while(nums[i]>0)
            {
                int lastDigit=nums[i]%10;
                digit_sum+=lastDigit;
                nums[i]/=10;
            }
        }
        return abs(el_sum-digit_sum);
    }
};