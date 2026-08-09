class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry { true };
        int i = digits.size()-1;
        while (carry) {
            if (i == -1) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
            if (digits[i] + 1 == 10) {
                digits[i] = 0;
                i--;
                continue;
            }
            digits[i]++;
            carry = false;
            
        }
        return digits;
        
    }
};
