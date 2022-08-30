class Solution {
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public void reverse(int[] nums, int i, int j) {
        while(i < j) swap(nums, i++, j--);
    }
    
    public void nextPermutation(int[] nums) {
        int ind = -1; 
        for(int i=nums.length-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }
        
        if(ind == -1) {
            reverse(nums, 0, nums.length-1);
            return;
        }
        
        int jnd = -1;
        for(int i=nums.length-1; i>=0; i--) {
            if(nums[i] > nums[ind]) {
                jnd = i;
                break;
            }
        }
        swap(nums, ind, jnd);
        reverse(nums, ind+1, nums.length-1);
    }
}