class Solution {
public:
    int arrangeCoins(int n) {
        int steps=1;
        int ans=0;
        while (n>=steps)
        {
            if (steps<=n)
            {
                ans++;
                n=n-steps;
                steps++;
            }
            
        }
        return ans;
    }
};