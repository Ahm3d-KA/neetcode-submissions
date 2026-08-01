class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int j=0;
        unordered_map<char, int> m;
        for (char t : tasks) {
            m[t]++;
        }

        priority_queue<int, vector<int>, less<int>> xh;

        for (auto [_, c] : m) {
            xh.push(c);
        }

        int time = 0;
        queue<pair<int, int>> q;
        pair<int, int> task_time;
        while (!xh.empty() || !q.empty()) {
            if (!xh.empty()) {

                task_time = {xh.top()-1, time+n}; xh.pop();
                if (task_time.first > 0) {
                    q.push(task_time);
                }

            }
            if (!q.empty()) {
                if (q.front().second <= time) {
                    task_time = q.front(); q.pop();
                    xh.push(task_time.first);
                }
            }
            
            time++;

        }
        return time;

        
    }
};
