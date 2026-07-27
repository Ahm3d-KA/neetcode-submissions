class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l=0, r=m*n-1, p;
        int val;

        while (l <= r) {
            p = (l + r) / 2;
            val = matrix[p / n][p % n];
            if (target > val) {
                l = p + 1;
            }
            else if (target < val) {
                r = p - 1;
            }
            else {


                return true;
            }
        }
        return false;
    }
};
