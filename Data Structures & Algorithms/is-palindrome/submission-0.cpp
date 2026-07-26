class Solution {
public:
    bool isPalindrome(string s) {
std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
s.erase(end_pos, s.end());
std::transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return std::tolower(c); });

s.erase(std::remove_if(s.begin(), s.end(), 
[]( auto const& c ) -> bool { return !std::isalnum(c); } ), s.end());


        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }
};
