/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> old_to_new;
    Node* dfs(Node* node) {
        Node* copy = new Node(node->val);
        old_to_new[node] = copy;
        for (Node* n : node->neighbors) {
            if (old_to_new.find(n) == old_to_new.end()) {
                dfs(n);
            }
            copy->neighbors.push_back(old_to_new[n]);
        }
        return copy;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
        
        
    }
};
