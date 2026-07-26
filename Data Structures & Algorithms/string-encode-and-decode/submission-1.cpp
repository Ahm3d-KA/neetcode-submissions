class Solution {
public:

    string encode(vector<string>& strs) {
        string res; 
        for (string str : strs) {
            res = res + to_string(str.length()) + "#" + str;
        }
        return res;

    }

    vector<string> decode(string s) {
        string num, ss;
        int strlength;
        vector<string> res;
        int i=0;
        while (i<s.length()) {
            while (s[i] != '#') {
                num += s[i];
                i++;
            }
            // convert to num
            strlength = stoi(num);
            num = "";
            ss = s.substr(i+1, strlength);

            res.push_back(ss);
            i += strlength + 1;
        }
        return res;

    }
};
