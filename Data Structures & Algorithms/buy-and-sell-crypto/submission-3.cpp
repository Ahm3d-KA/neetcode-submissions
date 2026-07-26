class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0, l=0, r=1;
        while (r<prices.size()) {
            if (prices[r] < prices[l]) {
                l=r; r++;
            }
            else {
                maxp = max(maxp, prices[r] - prices[l]);
                r++;
            }
        }
        return maxp;
    }
};
