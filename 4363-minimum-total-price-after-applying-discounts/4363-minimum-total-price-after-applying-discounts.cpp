class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        double ans=0;
        int i=0;
        for (; i < discounts.size(); i++)
        {
            if(i<prices.size()) ans+=prices[i]-(prices[i]*discounts[i]/100.0);
            else break;
            
        }
        for(;i<prices.size();i++)
        {
            ans+=prices[i];
        }
        
        return ans;
    }
};