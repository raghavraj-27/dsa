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
    ListNode* createList(int ind, vector<vector<int>>& arr) {
        if(ind >= arr.size()) return NULL;
        
        int i=0;
        ListNode* new_node = new ListNode(arr[ind][i]); 
        ListNode* head = new_node; 
        
        for(i=1; i<arr[ind].size(); i++) {
            new_node->next = new ListNode(); 
            new_node = new_node->next;
            new_node->val = arr[ind][i]; 
        }
        
        new_node->next = createList(ind+1, arr);
        return head;
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<vector<int>> arr;
        // vector<int> v; 
        
        ListNode* ptr = head; 
        for(int i=1; ptr!=NULL; i++) {
            vector<int> v;
            while(ptr != NULL and v.size()<i) {
                v.push_back( ptr->val );
                ptr = ptr->next;
            }
            arr.push_back(v);
            if(arr.back().size()%2 == 0) {
                reverse(arr.back().begin(), arr.back().end());
            }
        }
        
        return createList(0, arr);
    }
};