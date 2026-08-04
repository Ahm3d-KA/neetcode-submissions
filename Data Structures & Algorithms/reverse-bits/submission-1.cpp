class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        int i =31;
        while (n!=0) {
            res += (1 & n) * pow(2, i);
            i--;
            n >>= 1;

        }
        return res;
    }
};
