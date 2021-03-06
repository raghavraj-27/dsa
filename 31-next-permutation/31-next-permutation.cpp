class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); 
        int ind = -1, diff = INT_MAX; 
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind = i; 
                break;
            }
        }
        
        if(ind == -1) {
            reverse(nums.begin(), nums.end()); 
            return;
        }
        
        int ind2;
        for(int i=n-1; i>=0; i--) {
            if(nums[i] > nums[ind] and abs(nums[i] - nums[ind]) < diff) {
                ind2 = i;
                break;
            }
        }
        
        int temp = nums[ind]; 
        nums[ind] = nums[ind2]; 
        nums[ind2] = temp;
        
        sort(nums.begin()+ind+1, nums.end());
        // auto it = nums.begin(); 
        // advance(it, ind+1);
        // reverse(it, nums.end()); 
        return;
    }
};