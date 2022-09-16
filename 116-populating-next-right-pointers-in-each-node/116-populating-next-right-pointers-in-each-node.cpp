/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        
        Node* node = root;
        while(node->left != nullptr) {
            Node* curr = node;
            while(curr != nullptr) {
                if(curr->left != nullptr) {
                    curr->left->next = curr->right;
                }
                if(curr->right !=nullptr and curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            node = node->left;
        }
        
        return root;
    }
};