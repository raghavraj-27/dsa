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
    ListNode* middleNode(ListNode* head) {
        int n = 0; 
        ListNode* ptr = head; 
        while(ptr != NULL) {
            n++; 
            ptr = ptr->next;
        }
        
        int mid = n/2 +1;
        ptr = head; 
        while(mid!=1) {
            ptr = ptr->next; 
            mid--;
        }
        
        return ptr;
    }
};