class Solution {
public:
    int bestClosingTime(string customers) {
        int panalty=0;
        for (int i = 0; i < customers.size(); i++)
        {
            if(customers[i]=='Y') panalty++;

        }
        int minPanalty=panalty;
        int ans=0;
        for (int i = 0; i <= customers.size(); i++)
        {
            if(customers[i]=='Y') panalty--;
            else panalty++;

            if (panalty < minPanalty)
            {
                minPanalty = panalty;
                ans = i + 1;
            }
        }
        return ans;
    }
};