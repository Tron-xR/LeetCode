class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;

        for (int i = 0; i < prices.size(); i++) {
            int price = prices[i];

            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    price -= prices[j];
                    break;
                }
            }

            ans.push_back(price);
        }

        return ans;
    }
};