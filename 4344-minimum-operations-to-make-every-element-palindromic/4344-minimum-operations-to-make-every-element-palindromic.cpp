#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    inline static vector<long long> even_p;
    inline static vector<long long> odd_p;
    inline static bool initialized = false;

    static void precompute() {
        if (initialized) return;
        for (int len = 1; len <= 10; ++len) {
            int k = (len + 1) / 2;
            long long start = 1;
            for (int i = 1; i < k; ++i) start *= 10;
            long long end = start * 10 - 1;
            if (len == 10) end = 20000;
            
            for (long long half = start; half <= end; ++half) {
                long long p = half;
                long long temp = (len % 2 == 1) ? half / 10 : half;
                while (temp > 0) {
                    p = p * 10 + (temp % 10);
                    temp /= 10;
                }
                if (p % 2 == 0) even_p.push_back(p);
                else odd_p.push_back(p);
            }
        }
        sort(even_p.begin(), even_p.end());
        sort(odd_p.begin(), odd_p.end());
        initialized = true;
    }

public:
    long long minOperations(vector<int>& nums) {
        precompute();
        
        long long total_ops = 0;
        for (int x : nums) {
            const auto& arr = (x % 2 == 0) ? even_p : odd_p;
            auto it = lower_bound(arr.begin(), arr.end(), (long long)x);
            
            long long min_diff = -1;
            if (it != arr.end()) {
                min_diff = *it - x;
            }
            if (it != arr.begin()) {
                long long diff_prev = x - *(it - 1);
                if (min_diff == -1 || diff_prev < min_diff) {
                    min_diff = diff_prev;
                }
            }
            total_ops += min_diff / 2;
        }
        return total_ops;
    }
};