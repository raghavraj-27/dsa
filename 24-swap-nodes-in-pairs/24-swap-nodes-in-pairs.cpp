class Solution {
public:
    ListNode* func(ListNode* ptr1, ListNode* ptr2) {
        if(ptr1==NULL) return nullptr;
        if(ptr2==NULL) return ptr1;
        
        ListNode *para1 = ptr2->next;
        ListNode *para2 = nullptr;
        if(para1 != nullptr) 
            para2 = ptr2->next->next;
        
        ptr2->next = ptr1;
        
        ptr1->next = func(para1, para2);
        return ptr2;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        return func(head, head->next);
    }
};
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