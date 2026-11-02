class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int x : nums) {
            pq.push(x);
        }

        long long score = 0;

        while (k--) {
            int m = pq.top();
            pq.pop();

            score += m;

            pq.push(m + 1);
        }

        return score;
    }
};