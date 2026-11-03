class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) continue;
            for (int dir : {-1, 1}) {
                vector<int> arr = nums;
                int curr = i;

                while (curr >= 0 && curr < n) {
                    if (arr[curr] == 0) {
                        curr += dir;
                    }
                    else {
                        arr[curr]--;
                        dir *= -1;
                        curr += dir;
                    }
                }

                bool valid = true;

                for (int x : arr) {
                    if (x != 0) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    ans++;
            }
        }

        return ans;
    }
};