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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre, *mid, *nex;
        if(head == nullptr or head->next==nullptr) return head;
        pre = head; mid = head->next; nex = mid->next;
        if(nex == nullptr) {
            if(pre->val == mid->val) return nullptr;
            else return head;
        }
        
        ListNode *h1 = head, *h2 = head->next;
        
        repeat : if(h1->val == h2->val) {
            while(h2!=nullptr and h2->val == h1->val) {
                h2 = h2->next;
            }
            head = h2;
        }
        
        if(head == nullptr or head->next==nullptr) return head;
        h1 = head, h2 = head->next;
        if(h1->val == h2->val) goto repeat; // recursion 
        
        pre = head; mid = head->next; nex = mid->next;
        while(nex != nullptr) {
            if(mid->val == nex->val) {
                while(nex != nullptr and nex->val == mid->val) {
                    nex = nex->next;
                }
                pre->next = nex;
                mid = nex;
                if(nex != nullptr) nex = nex->next;
            }
            else {
                pre = mid;
                mid = nex;
                if(nex != nullptr) nex = nex->next;
            }
        }
        
        return head;
    }
};