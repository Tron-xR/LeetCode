class Solution {
public:
    int minRotations(string s) {
        int ans = 0, curr = 0;

        for(char c : s) {
            int digit = c - '0';
            int diff = abs(digit - curr);
            ans += min(diff, 10 - diff);
            curr = digit;
        }

        return ans;
    }
};