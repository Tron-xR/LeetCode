class Solution {
public:

    bool isPrime(int n)
    {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int minOperations(vector<int>& nums) {

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];

            if (i % 2 == 0)
            {
                // Need prime
                while (!isPrime(x))
                {
                    x++;
                    ans++;
                }
            }
            else
            {
                while (isPrime(x))
                {
                    x++;
                    ans++;
                }
            }
        }

        return ans;
    }
};