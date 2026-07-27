class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res(temperatures.size(), 0);
        stack<pair<int, int>> s;
        pair<int, int> temp;
        s.push({temperatures[0], 0});
        for (int i=1; i<temperatures.size(); i++) {
            while (!(s.empty()) && temperatures[i] > s.top().first) {
                temp = s.top(); s.pop();
                res[temp.second] = i - temp.second;

            }
            s.push({temperatures[i], i});
        }
        return res;
        
    }
};
