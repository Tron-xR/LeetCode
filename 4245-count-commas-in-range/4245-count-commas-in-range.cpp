class Solution {
public:
    long long countCommas(int n) {

        long long ans = 0;

        long long start = 1000;
        int commas = 1;

        while (start <= n) {

            long long end = start * 1000 - 1;

            long long countNumbers =
                min((long long)n, end) - start + 1;

            ans += countNumbers * commas;

            start *= 1000;
            commas++;
        }

        return ans;
    }
};