class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> mh;
        for (int s : stones) {
            mh.push(s);
        }
        int s, t;
        while(mh.size() > 1) {
            s = mh.top(); mh.pop();
            t = mh.top(); mh.pop();
            if (s == t) {
                continue;
            }
            mh.push(abs(s - t));


        }
        return mh.size() == 1 ? mh.top() : 0;
    }
};
