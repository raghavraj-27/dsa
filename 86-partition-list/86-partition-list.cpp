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
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*> v;
        ListNode* ptr = head; 
        ListNode* prev = nullptr;
        ListNode* newhead = nullptr;
        
        while(ptr != nullptr) {
            // ListNode* temp = ptr;
            while(ptr != nullptr and ptr->val < x) {
                v.push_back(ptr);
                if(ptr != head and prev != nullptr) {
                    prev->next = ptr->next;
                } else {
                    head = ptr->next;
                }
                ptr = ptr->next;
            }
            if(prev != nullptr) {
                prev->next = ptr;
            }
            
            prev = ptr;
            if(ptr != nullptr)
                ptr = ptr->next;
        }
        if(v.size() == 0) return head;
        
        for(int i=0; i<v.size(); i++) {
            if(i == 0) {
                newhead = v[0];
            } else {
                v[i-1]->next = v[i];
            }
        }
        
        v[v.size()-1]->next = head;
        return newhead;
        // return nullptr;
    }
};

