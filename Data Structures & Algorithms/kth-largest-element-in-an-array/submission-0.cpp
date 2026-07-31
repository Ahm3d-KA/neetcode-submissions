class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for (int n : nums) {
            if (minh.size() == k) {
                if (minh.top() < n) {
                    minh.pop();
                    minh.push(n);
                }
            }
            else {
                minh.push(n);
            }
        }
        return minh.top();
    }
};
