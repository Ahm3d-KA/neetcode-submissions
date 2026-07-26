class Solution {
public:
    bool isValid(string s) {
        stack<char> bracs;
        if (s.length()%2 !=0) {
            return false;
        }
        for (char b : s) {
            if (b == '[' || b == '(' || b == '{') {
                bracs.push(b);
            }
            else if (bracs.empty()) {
                return false;
            }
            else {
                if ((bracs.top() == '(' && b == ')') ||
                (bracs.top() == '{' && b == '}') || 
                (bracs.top() == '[' && b == ']')) {
                    bracs.pop();
                }
                else {
                    return false;
                }
            }
        }
        return bracs.empty();
        
    }
};
