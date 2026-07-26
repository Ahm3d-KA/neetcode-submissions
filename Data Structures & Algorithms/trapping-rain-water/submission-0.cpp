class Solution {
public:
    int trap(vector<int>& height) {
        // int volt;
        int sum = 0;
        // volt = min(height[l], height[r] - height[i])

        vector<int>pref(height.size());
        pref[0] = height[0];
        for (int i=1; i<height.size(); i++) {
            pref[i] = max(height[i], pref[i-1]);
        }

        vector<int>suff(height.size());
        suff[height.size()-1] = height[height.size()-1];
        for (int i=height.size()-2; i>=0; i--) {
            suff[i] = max(height[i], suff[i+1]);
        }

        int l,r;

        for (int i=0; i<height.size(); i++) {
            // l=i+1; r=height.size()-1;
            // while (l < r) {
                sum+= min(pref[i], suff[i]) - height[i];

            //}
        }
        return sum;
        
    }
};
