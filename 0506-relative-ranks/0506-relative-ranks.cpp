class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), greater<int>());

        map<int, string> ranks;

        for(int i = 0; i < sorted.size(); i++) {
            if(i == 0)
                ranks[sorted[i]] = "Gold Medal";
            else if(i == 1)
                ranks[sorted[i]] = "Silver Medal";
            else if(i == 2)
                ranks[sorted[i]] = "Bronze Medal";
            else
                ranks[sorted[i]] = to_string(i + 1);
        }

        vector<string> ans;

        for(int i = 0; i < score.size(); i++) {
            ans.push_back(ranks[score[i]]);
        }

        return ans;
    }
};