class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;

        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                if (j == i) continue;

                for (int k = 0; k < digits.size(); k++) {
                    if (k == i || k == j) continue;

                    int num = 100 * digits[i] + 10 * digits[j] +digits[k];

                    if (digits[i] == 0) continue;

                    if (digits[k] % 2 == 0) st.insert(num);
                }
            }
        }

        return st.size();
    }
};