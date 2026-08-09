class Solution {
private:
    double pow(double x, int n) {
        if (!n) return 1.0;
        if (n==1) return x;
        double half = pow(x, n/2);
        if (n == 1) return x;
        if (n == 0) return 1;
        if (n % 2 == 0) {
            return half * half;
        }
        return half * half * x;

    }
public:
    double myPow(double x, int n) {
        // if (!n) return 1;
        // if(!x) return 0;
        // if (n == 1) return x;
        // if (x == 1) return 1;
        // if (x == -1) {
        //     if (n % 2 == 0) {
        //         return 1;
        //     }
        //     return -1;
        // }
        long long N = n;
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        return pow (x, N);
    }
};
