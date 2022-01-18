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
    int pairSum(ListNode* head) {
        vector<int> arr; 
        ListNode* ptr = head; 
        while(ptr != NULL) {
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        int ans = INT_MIN;
        int left = 0, right = arr.size()-1;
        while(left < right) {
            ans = max(ans, arr[left] + arr[right]);
            left++; right--;
        }
        return ans;
    }
};