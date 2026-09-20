class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int start = 0; start < n; start++) {
            int score = 0;

            for (int i = 0; i < n - 1; i++) {
                if (s[(start + i) % n] == s[(start + i + 1) % n])
                    score++;
            }

            if (score == k)
                ans++;
        }

        return ans;
    }
};