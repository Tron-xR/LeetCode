class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        float n=salary.size();
        float sum=accumulate(salary.begin()+1,salary.end()-1,0);
        return sum/(n-2.0);
    }
};