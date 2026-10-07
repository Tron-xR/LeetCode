class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;

        for (string &chunk : chunks) {
            s += chunk;
        }

        unordered_map<string, int> freq;

        int n = s.size();
        string word;

        for (int i = 0; i < n; i++) {

            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                word += c;
            }

            else if (c == '-' &&
                     i > 0 &&
                     i + 1 < n &&
                     s[i - 1] >= 'a' && s[i - 1] <= 'z' &&
                     s[i + 1] >= 'a' && s[i + 1] <= 'z') {
                word += c;
            }

            else {
                if (!word.empty()) {
                    freq[word]++;
                    word.clear();
                }
            }
        }

        if (!word.empty()) {
            freq[word]++;
        }

        vector<int> ans;

        for (string &q : queries) {
            ans.push_back(freq[q]);
        }

        return ans;
    }
};