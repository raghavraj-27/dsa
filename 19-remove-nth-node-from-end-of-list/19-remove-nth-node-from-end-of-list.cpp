/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // BRUTE FORCE
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* iter = head;
        int len = 0, i = 1;
        // finding the length of linked list
        while(iter) iter = iter -> next, len++;    
        
        // if head itself is to be deleted, just return head -> next
        if(len == n) 
            return head -> next;   
        
        // iterate first len-n nodes
        for(iter = head; i < len - n; i++) 
            iter = iter -> next; 
        
        // remove the nth node from the end
        iter -> next = iter -> next -> next;      
        return head;
    }
};