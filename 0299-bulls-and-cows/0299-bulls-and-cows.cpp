class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        int cow=0;

        vector<int> secretFreq(10,0);
        vector<int> guessFreq(10,0);
        for (int i = 0; i < secret.size(); i++)
        {
            if(secret[i]==guess[i]) bull++;

            else{
                secretFreq[secret[i]-'0']++;
                guessFreq[guess[i]-'0']++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            cow+=min(secretFreq[i],guessFreq[i]);
        }
        return to_string(bull)+'A'+to_string(cow)+'B';
    }
};