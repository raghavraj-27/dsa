/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // store deep copy of each node of the given linked list
        unordered_map<Node*, Node*> mp;
        Node *ptr = head;
        while(ptr != NULL) {
            Node *new_node = new Node(ptr->val);
            mp[ptr] = new_node;
            ptr = ptr->next;
        }
        
        // 
        ptr = head;
        while(ptr != NULL) {
            Node *my_node = mp[ptr];
            my_node->next = mp[ptr->next];
            my_node->random = mp[ptr->random];
            ptr = ptr->next;
        }
        
        return mp[head];
    }
};