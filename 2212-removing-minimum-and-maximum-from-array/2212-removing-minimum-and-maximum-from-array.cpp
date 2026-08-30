class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int high=nums.size()-1;
        int low=0;
        int maxIndex=-1;
        int minIndex=-1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==maxi) maxIndex=i;
            if(nums[i]==mini) minIndex=i;
        }

        int n = nums.size();
        int front = max(maxIndex, minIndex) + 1;
        int back = n - min(maxIndex, minIndex);

        int both = min(maxIndex, minIndex) + 1 + n - max(maxIndex, minIndex);
        return min({front,back,both});
    }
};