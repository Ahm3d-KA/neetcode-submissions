class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int,int>>> minh;
        int dist;
        for (int i=0; i<points.size(); i++) {
            dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            if (minh.size() == k) {
                if (minh.top().first > dist) {
                    minh.pop();
                    minh.push({dist, i});
                }
            }
            else {
            minh.push({dist, i});

            }
        }

        vector<vector<int>> res;
        while (!minh.empty()) {
            res.push_back(points[minh.top().second]);
            minh.pop();
        }
        return res;

    }
};
