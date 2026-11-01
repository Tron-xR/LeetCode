class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        int answer1 = 0, answer2 = 0;

        for (int x : nums1) {
            if (st2.count(x)) {
                answer1++;
            }
        }

        for (int x : nums2) {
            if (st1.count(x)) {
                answer2++;
            }
        }

        return {answer1, answer2};
    }
};