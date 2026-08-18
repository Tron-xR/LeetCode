class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++)
        {
            set<int> st;

            for (int j = i; j < i + k; j++)
            {
                st.insert(nums[j]);
            }

            for (int x : st)
            {
                freq[x]++;
            }
        }

        int ans = -1;

        for (auto it : freq)
        {
            if (it.second == 1)
            {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};