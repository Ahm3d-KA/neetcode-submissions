class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int l=0, r=1;
        while (r < prices.size()) {
            if (prices[r] > prices[l]) {
                maxp = max(prices[r] - prices[l], maxp);
            }
            if (prices[r] < prices[l]) {
                l = r;
            }
            r++;
        }
        return maxp;

    }
};
