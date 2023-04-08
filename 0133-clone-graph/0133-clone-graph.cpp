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
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        queue<Node*>original,copy;
        unordered_map<int,Node*>mp;
        Node* root=new Node(node->val);
        mp[node->val]=root;
        original.push(node),copy.push(root);
        while(!copy.empty())
        {
            Node* o_node=original.front();
            original.pop();
            Node* c_node=copy.front();
            copy.pop();
            for(auto ptr: o_node->neighbors)
            {
                if(mp.find(ptr->val)==mp.end())
                {
                    Node* new_node=new Node(ptr->val);
                    mp[ptr->val]=new_node;
                    c_node->neighbors.push_back(new_node);
                    copy.push(new_node);
                    original.push(ptr);
                }
                else{
                    c_node->neighbors.push_back(mp[ptr->val]);
                    
                }
            }
        }
        
        return root;
        
    }
};