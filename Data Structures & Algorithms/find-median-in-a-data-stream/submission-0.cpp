class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> sh;
    priority_queue<int, vector<int>, greater<int>> lh;
    MedianFinder() {
        
        
    }
    
    void addNum(int num) {
        sh.push(num);
        while (!lh.empty() && sh.top() > lh.top()) {
            lh.push(sh.top()); sh.pop();
        }
        while (lh.size() > sh.size()) {
            sh.push(lh.top()); lh.pop();
        }
        while (sh.size()-1 > lh.size()) {
            lh.push(sh.top()); sh.pop();

        }
    }
    
    double findMedian() {
        if (sh.size() == lh.size()) {
            return (((double)sh.top() + (double)lh.top()) / 2);
        } 
        return sh.top();
        
    }
};
