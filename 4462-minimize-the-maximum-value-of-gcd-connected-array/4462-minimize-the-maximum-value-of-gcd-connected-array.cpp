
class Solution {
public:
    int smallestPrimeFactor(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return i;
        }
        return x;
    }

    long long minimumMaxValue(int n, int index, int value) {
        int left = index;
        int right = n - index - 1;

        if (value == 1) {
            return -1;
        }

        int p = smallestPrimeFactor(value);

        int maxLeft = (value - p) / 2;

        if (left > maxLeft) {
            return -1;
        }
        if (right == 0) {
            return value;
        }
        long long ans = value + p;
        ans += 2LL * (right - 1);

        return ans;
    }
};
