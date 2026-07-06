int NoOfDays(vector<int>& weights,int capacity){
    int day=1;
    int load=0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load+weights[i]>capacity)
        {
            day=day+1;
            load=weights[i];
        }
        else load+=weights[i];
        
    }
    return day;
    
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while (low<=high)
        {
            int mid=(low+high)/2;
            if(NoOfDays(weights,mid)<=days) high=mid-1;

            else low=mid+1;
        }
        return low;
    }
};