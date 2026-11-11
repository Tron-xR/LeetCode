class Solution {
public:
    long long countValidSubstrings(string s) {
        int last_a = -1, last_ab = -1, last_abc = -1;
        long long valid_count = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') {
                last_a = i;
            } else if (s[i] == 'b') {
                last_ab = last_a;
            } else if (s[i] == 'c') {
                last_abc = last_ab;
            }
            valid_count += (i - last_abc);
        }
        
        return valid_count;
    }
};