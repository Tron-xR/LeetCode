class Solution {
public:
    int maxProduct(int n) {
        vector<int> temp;
        while(n>0)
        {
            int lastDigit=n%10;
            temp.push_back(lastDigit);
            n/=10;
        }
        sort(temp.rbegin(),temp.rend());
        return temp[0]*temp[1];
    }
};