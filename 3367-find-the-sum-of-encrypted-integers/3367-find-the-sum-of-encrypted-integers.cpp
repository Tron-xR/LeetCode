int encrypt(int x)
{
    int cnt=0;
    int maxi=INT_MIN;
    int num=0;
    while(x>0)
    {
        int lastDigit=x%10;
        maxi=max(maxi,lastDigit);
        cnt++;
        x/=10;
    }
    for(int i=1;i<=cnt;i++)
    {
        num=num*10+maxi;
    }
    return num;
}

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=encrypt(nums[i]);
        }
        return sum;
    }
};