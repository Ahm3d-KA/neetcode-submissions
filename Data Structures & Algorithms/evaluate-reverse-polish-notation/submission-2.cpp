class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a,b;
        for (string t : tokens) {
            if (isdigit(t[0]) || t.length()>1) {
                s.push(stoi(t));
            }
            else {
                a=s.top(); s.pop();
                b=s.top(); s.pop();
                switch(t[0]) {
                    case '+':
                        s.push(a+b);
                        break;
                    case '-':
                        s.push(b-a);
                        break;
                    case '*':
                        s.push(a*b);
                        break;
                    case '/':
                        s.push(b/a);
                        break;
                }
            }
        }
        return s.top();
        
    }
};
