int numberOfK(vector<int>& nums,int mid)
{
    int k=1;
    int sum=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum+nums[i]<=mid) sum+=nums[i];
        else {k++;
            sum=nums[i];}
    }
    return k;
}

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while (low<=high)
        {
            int mid=(low+high)/2;
            int a=numberOfK(nums,mid);
            if(a>k) low=mid+1;
            else high=mid-1;
        }
        return low;
        
    }
};