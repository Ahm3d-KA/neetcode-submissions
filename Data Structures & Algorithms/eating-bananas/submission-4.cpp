class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l{1}, r{ *max_element(piles.begin(), piles.end()) };
        int k { r/2 };
        int hours {};
        int res { r+1 };

        while (l <= r) {
             k = (l + r) / 2;
              hours = 0;
            for (int p : piles) {
                hours += p / k;
                if (p % k) hours++;
            }
            if (hours > h) {

                l = k+1;
               
                
            }
            else if (hours <= h) {
                res = min(res, k);
                r = k-1;
            }
           
            
        }
        return res;



        // while (hours > h) {
        //     k++;
        //     hours = 0;
        //     for (int p : piles) {
        //         hours += p / k;
        //         if (p % k) hours++;
        //     }
        // }
        // return k;

    }
};
