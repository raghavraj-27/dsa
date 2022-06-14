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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        do {
            if(slow == NULL or fast == NULL or fast->next == NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        } while(slow != fast);
        
        fast = head;
        
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};