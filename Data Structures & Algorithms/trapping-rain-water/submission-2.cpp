class Solution {
public:
    int trap(vector<int>& height) {
        int maxl=height[0], maxr=height[height.size()-1], l=0, r=height.size()-1;
        int sum = 0;
        while (l < r) {
            if (maxl < maxr) {
                l++;
                maxl = max(maxl, height[l]);
                if (maxl - height[l] > 0) {
                    sum += maxl - height[l];
                }
                
            }
            else {
                r--;
                maxr = max(maxr, height[r]);
                if (maxr - height[r] > 0) {
                    sum += maxr - height[r];
                }
            }
        }
        return sum;
 
    }
};
