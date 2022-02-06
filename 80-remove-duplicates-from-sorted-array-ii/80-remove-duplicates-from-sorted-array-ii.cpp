class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1, n=nums.size(); 
        int i=1,j;
        
        while(i < n) {
            if(nums[i-1] != nums[i]) {
                cnt = 1;
            }
            else if(nums[i-1] == nums[i]) {
                cnt++;
            }
            
            if(cnt > 2) {
                int t = i, p = i+1;
                while(p<n and nums[p-1]==nums[p]) p++;
                int gap = (p-t);
                while(p < n) {
                    nums[t++] = nums[p++];
                }
                n = n - gap;
                continue;
            }
            i++;
        }
        return n;
    }
};