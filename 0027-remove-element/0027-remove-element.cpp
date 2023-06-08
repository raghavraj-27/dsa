class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 1; 
        int n = nums.size();
        
        while(i < n) {
            if(nums[i] != val) {
                i++; j++;
            }
            else {
                while(j < n and nums[j] == val) {
                    j++;
                }
                
                if(j == n) break;
                
                swap(nums[i], nums[j]);
                i++;
                j = i+1;
            }
        }
        
        return i;
    }
};