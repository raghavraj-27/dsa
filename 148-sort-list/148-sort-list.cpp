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
    void findMid(ListNode* head, ListNode** first, ListNode** second) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast != nullptr and fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        *first = head;
        *second = slow->next;
        slow->next = nullptr;
    }
    
    ListNode* mergeTwoLinkedList(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLinkedList(l1->next, l2);
            return l1;
        }
        
        if(l1->val > l2->val) {
            l2->next = mergeTwoLinkedList(l1, l2->next);
            return l2;
        }
        
        return nullptr;
    }
    
    void mergeSort(ListNode** head) {
        ListNode* curr = *head;
        
        if(curr == nullptr or curr->next == nullptr) 
            return;
        
        ListNode* first, *second;
        
        findMid(curr, &first, &second);
        
        mergeSort(&first);
        
        mergeSort(&second);
        
        *head = mergeTwoLinkedList(first, second);
    }
    
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);
        return head;
    }
};