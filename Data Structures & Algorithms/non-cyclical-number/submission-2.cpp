class Solution {
private:
    int sumOfSquares(int n) {
        string snum = to_string(n);
        int res {};
        for (char n : snum) {
            res += pow(n - '0', 2);
        }
        return res;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        if (slow == 1) return true;
        int fast = sumOfSquares(n);
        while (slow != fast) {
            if (fast == 1) return true;
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }
        return false;
        
    }
};
