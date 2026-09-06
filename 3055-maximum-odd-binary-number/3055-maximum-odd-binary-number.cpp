class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;

        for(char c : s)
        {
            if(c == '1')
                ones++;
        }

        string ans;
        ans.append(ones - 1, '1');
        ans.append(s.size() - ones, '0');
        ans += '1';

        return ans;
    }
};