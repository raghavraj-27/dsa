class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        
        Node* root = new Node(node->val);
        queue<Node*> orignal, copy;
        unordered_map<int, Node*> exist;
        exist[node->val] = root;
        
        orignal.push(node); copy.push(root);
        while(not copy.empty()) {
            Node* o_node = orignal.front();
            orignal.pop();
            Node* c_node = copy.front();
            copy.pop();
            
            vector<Node *> v = o_node->neighbors;
            for(auto ptr : v) {
                int value = ptr->val;
                if(exist.find(value) != exist.end()) {
                    c_node->neighbors.push_back(exist[value]);
                } else {
                    Node* new_node = new Node(value);
                    c_node->neighbors.push_back(new_node);
                    
                    exist[value] = new_node;
                    
                    copy.push(new_node);
                    orignal.push(ptr);
                }
            }
        }
        
        return root;
    }
};

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

