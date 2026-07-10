class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> original=nums;
        int sum=0;
        int n=nums.size();

        vector<int> digitRange;
        for (int i = 0; i < n; i++)
        {
        int maxi=INT_MIN;
        int mini=INT_MAX;
            while (nums[i]>0)
            {
                int lastDigit=nums[i]%10;
                maxi=max(maxi,lastDigit);
                mini=min(mini,lastDigit);
                nums[i]/=10;
            }
            digitRange.push_back(maxi-mini);
            
        }

        int maxRange=*max_element(digitRange.begin(),digitRange.end());
        for (int i = 0; i < n; i++)
        {
            if (digitRange[i]==maxRange)
            {
                sum+=original[i];
            }
            
        }
        return sum;
    }
};