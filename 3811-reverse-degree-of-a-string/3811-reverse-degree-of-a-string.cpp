class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for (int i = 0; i < s.size(); i++)
        {
            int product=('z'-s[i]+1)*(i+1);
            sum+=product;
        }
        return sum;
    }
};