bool isVowel(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size(),0);
        for (int i = 0; i < words.size(); i++)
        {
            if (isVowel(words[i][0])&&isVowel(words[i].back())) prefix[i]=1;
            if(i>0) prefix[i]+=prefix[i-1];
            
        }
        vector<int> ans;
        for(auto &it:queries)
        {
            int left=it[0];
            int right=it[1];

            if(left==0) ans.push_back(prefix[right]);
            else ans.push_back(prefix[right]-prefix[left-1]);
        }
        return ans;
    }
};