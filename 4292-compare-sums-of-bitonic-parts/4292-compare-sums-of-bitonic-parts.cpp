class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        int low=1;
        int high=n-2;
        int peak=-1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) 
            {
                peak=mid;
                break;
            }
            else if(nums[mid]<nums[mid-1]) high=mid-1;
            else low=mid+1;
        }
        long long leftSum=0;
        for (int i = 0; i <= peak; i++)
        {
            leftSum+=nums[i];
        }
        long long rightSum=0;
        for (int i = peak; i < n; i++)
        {
            rightSum+=nums[i];
        }
        if(leftSum>rightSum) return 0;
        else if(leftSum<rightSum) return 1;
        return -1;
    }
};