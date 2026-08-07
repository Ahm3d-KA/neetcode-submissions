class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=0;
        int maxp = 0;
        while (r < prices.size()) {
            if (prices[r] <= prices[l]) {
                l = r;
            }
            maxp = max(maxp, prices[r] - prices[l]);
            r++;
        }
        return maxp;
    }
};
