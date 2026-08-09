class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        
        sort(prices.rbegin() , prices.rend());
        sort(discounts.rbegin() , discounts.rend());

        double total = 0;
        int m = min(prices.size() , discounts.size());

        // Applying discounts
        for(int i = 0 ; i < m ; i++) {
            total += prices[i] * (100.0 - discounts[i]) / 100.0;
        }

        // Items without discounts
        for(int i = m ; i < prices.size() ; i++) {
            total += prices[i];
        }

        return total;
    }
};