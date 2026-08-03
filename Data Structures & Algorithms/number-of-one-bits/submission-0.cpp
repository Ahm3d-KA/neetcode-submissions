class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        do {
            sum += (1 & n);
            n = n >> 1;


        }
        while (n != 0);
        return sum;

    }
};
