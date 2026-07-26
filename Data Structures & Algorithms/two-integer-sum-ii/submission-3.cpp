class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>n = numbers;
        sort(n.begin(), n.end());
        int l = 0, r =n.size()-1;
        vector<int> res;
        while (true) {
            if (n[l] + n[r] == target) {
                res.push_back(distance(n.begin(), find(n.begin(), n.end(), n[l]))+1);
                res.push_back(distance(n.begin(), find(n.begin(), n.end(), n[r]))+1);
                return res;
                // return {find(n.begin(), n.end(), n[l])+1, find(n.begin(), n.end(), n[r])+1};
            }
            else if (n[l] + n[r] < target) {
                l++;
            }
            else {
                r--;
            }
        }
        
    }
};
