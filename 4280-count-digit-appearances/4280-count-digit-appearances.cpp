class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            while (nums[i]>0)
            {
                int lastDigit=nums[i]%10;
                nums[i]/=10;
                if(lastDigit==digit) cnt++;
            }
            
        }
        return cnt;
    }
};