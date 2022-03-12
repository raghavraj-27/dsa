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
        if(head == NULL) return head;
                
        Node* ptr = head; 
        while(ptr != NULL) {
            Node* temp = ptr->next; 
            Node* copy = new Node(ptr->val); 
            copy->next = temp;
            ptr->next = copy; 
            ptr = temp;
        }
        
        Node* itr = head; 
        while(itr != NULL) {
            itr->next->random = itr->random==NULL ? NULL : itr->random->next; 
            itr = itr->next->next;
        }
        
        itr = head; Node *front = head->next->next;
        Node* copy = head->next;  
        Node* myhead = copy;
        
        while(front != NULL) {
            copy->next = front->next;
            copy = front->next; 
            itr->next = front;
            itr = front;
            front = front->next->next;
        }
        
        itr->next = NULL;
        return myhead;
    }
};