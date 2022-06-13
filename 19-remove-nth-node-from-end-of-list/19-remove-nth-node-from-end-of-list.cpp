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
        ListNode* itr = head;
        int len = 0, i = 1;
        // finding the length of linked list
        while(itr) 
            itr = itr -> next, len++;    
        
        // if head itself is to be deleted, just return head -> next
        if(len == n) 
            return head -> next;   
        
        // iterate first len-n nodes
        for(itr = head; i < len - n; i++) 
            itr = itr -> next; 
        
        // remove the nth node from the end
        itr -> next = itr -> next -> next;      
        return head;
    }
};