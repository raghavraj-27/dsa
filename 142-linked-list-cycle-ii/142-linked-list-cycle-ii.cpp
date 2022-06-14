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
        unordered_set <ListNode*> st; 
        
        for(ListNode* ptr = head; ptr != NULL; ptr = ptr->next) {
            if(st.find(ptr) != st.end()) return ptr;
            st.insert(ptr);
        }
        
        return NULL;
    }
};