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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, remain = 0; 
        ListNode* ptr1 = l1, *ptr2 = l2;
        ListNode* prev;
        
        while(ptr1!=NULL and ptr2 != NULL) {
            int res = carry + ptr1->val + ptr2->val; 
            carry = res / 10; 
            remain = res % 10; 
            ptr1->val = remain; 
            
            prev = ptr1;
            ptr1 = ptr1->next; 
            ptr2 = ptr2->next;
        }
        
        while(ptr1 != NULL) {
            int res = carry + ptr1->val; 
            carry = res / 10; 
            remain = res % 10; 
            ptr1->val = remain; 
            
            prev = ptr1;
            ptr1 = ptr1->next; 
        }
        
        while(ptr2 != NULL) {
            int res = carry + ptr2->val; 
            carry = res / 10; 
            remain = res % 10;
            
            ListNode* new_node = new ListNode(carry); 
            prev->next = new_node;
            ptr1 = new_node;
            ptr1->val = remain; 
    
            prev = ptr1;
            ptr2 = ptr2->next; 
        }
        
        if(carry > 0) {
            ListNode* new_node = new ListNode(carry); 
            prev->next = new_node;
        }
        
        return l1;
    }
};