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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* ptr = head;
        
        while(ptr != nullptr) {
            ListNode* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        for(ListNode* ptr=head; ptr!=nullptr; ptr = ptr->next) {
            v.push_back(ptr -> val);
        }
        
        ListNode* newhead = new ListNode();
        ListNode* ptr;
        bool flag = true;

        
        int n = v.size();
        int prev_max = v[n-1];
        ListNode* prev;
        
        newhead->val = prev_max;
        prev = newhead;
        
        for(int i=n-2; i>=0; i--) {
            if(v[i] < prev_max) {
                continue;
            } else {
                prev_max = v[i];
                ListNode* newnode = new ListNode(v[i]);
                prev->next = newnode;
                prev = newnode;
            }
        }
        return reverse(newhead);
    }
};