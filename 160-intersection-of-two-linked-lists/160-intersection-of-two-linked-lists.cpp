/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = 0, cntB = 0; 
        ListNode *ptrA = headA, *ptrB = headB;
        
        while(ptrA != NULL) {
            cntA++;
            ptrA = ptrA->next;
        }
        while(ptrB != NULL) {
            cntB++;
            ptrB = ptrB->next;
        }
        
        ptrA = headA, ptrB = headB;
        
        if(cntA - cntB > 0) {
            int index = cntA - cntB; 
            while(index!=0) {
                index--; 
                ptrA = ptrA->next;
            }
        } else if(cntB - cntA > 0) {
            int index = cntB - cntA; 
            while(index != 0) {
                index--; 
                ptrB = ptrB->next;
            }
        }
        
        while(ptrA != ptrB) {
            ptrA = ptrA->next; 
            ptrB = ptrB->next;
        }
        
        return ptrA;
    }
};