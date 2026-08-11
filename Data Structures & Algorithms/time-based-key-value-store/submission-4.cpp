class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> &v {m[key]};
        int l{0}, r=v.size()-1;
        int m{};
        string res {};
        while (l <= r) {
            m = (l + r) / 2;
            if (timestamp >= v[m].second) {
                l = m + 1;
                res = v[m].first;
            }
            else if (timestamp < v[m].second) {
                r = m -1;
            }
        
        }
        return res;
    }
};
