class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        long long multiple=1;
        vector<int> ans;
        while (n>0)
        {
            int lastDigit=n%10;
            if (lastDigit!=0) ans.push_back(lastDigit*multiple);
            multiple*=10;
            n/=10;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};