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
public:
    Node *copied[105] = {nullptr};
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        int len = node->neighbors.size();
        Node *head = new Node(node->val);
        head->neighbors.assign(len, nullptr);
        copied[node->val] = head;
       
        for(int i = 0; i < len; ++i){
            if(copied[node->neighbors[i]->val] == nullptr)
                cloneGraph(node->neighbors[i]);
            head->neighbors[i] = copied[node->neighbors[i]->val];
        }

        return head;
    }
};
