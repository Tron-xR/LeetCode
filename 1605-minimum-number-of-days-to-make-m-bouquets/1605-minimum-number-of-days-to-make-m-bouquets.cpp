bool possibleDays(vector<int>& bloomDay,int day, int m, int k)
{
    int cnt=0;
    int numberOfBeque=0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i]<=day) cnt++;
        else {
            numberOfBeque+=cnt/k;
            cnt=0;
            }
    }
    numberOfBeque+=cnt/k;
    if(numberOfBeque>=m) return true;
    else return false;
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        if(1LL*m*k>bloomDay.size()) return -1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if (possibleDays(bloomDay,mid,m,k)==true) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};