class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();
        
        long long l = 0;
        long long r = (long long)start[n - 1] + d - start[0];
        long long ans = 0;
        auto check = [&](long long mi) {
            long long last = -1e18;
            for (int st : start) {
                long long current = max((long long)st, last + mi);
                if (current > (long long)st + d) {
                    return false;
                }
                last = current;
            }
            return true;
        };
        
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (check(mid)) {
                ans = mid; 
                l = mid + 1;
            } else {
                r = mid - 1; 
            }
        }
        
        return ans;
    }
};