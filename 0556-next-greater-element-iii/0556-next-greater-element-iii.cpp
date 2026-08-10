class Solution {
public:
    int nextGreaterElement(int n) {

        vector<int> temp;

        while (n > 0)
        {
            temp.push_back(n % 10);
            n /= 10;
        }

        reverse(temp.begin(), temp.end());

        int i = temp.size() - 2;

        while (i >= 0 && temp[i] >= temp[i + 1])
        {
            i--;
        }

        if (i < 0)
        {
            return -1;
        }

        int j = temp.size() - 1;

        while (temp[j] <= temp[i])
        {
            j--;
        }

        swap(temp[i], temp[j]);

        reverse(temp.begin() + i + 1, temp.end());

        long long result = 0;

        for (int x : temp)
        {
            result = result * 10 + x;

            if (result > INT_MAX)
            {
                return -1;
            }
        }

        return result;
    }
};