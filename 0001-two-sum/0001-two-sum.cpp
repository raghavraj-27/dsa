class Solution {
public:
    int search(int left, int right, vector<int> & nums, int val) {
        if(left > right)
            return -1; 
        
        int mid = (left + right) / 2; 
        if(nums[mid] > val)
            return search(left, mid-1, nums, val); 
        if(nums[mid] < val)
            return search(mid+1, right, nums, val);
        
        return mid;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> orignal; 
        for(auto val : nums) {
            orignal.push_back(val);
        }
        
        sort(nums.begin(), nums.end());
        vector<int> ans; 
        
        int ind1, ind2;
        for(int i=0; i<nums.size(); i++) {
            int x = target - nums[i];
            int j = search(i+1, nums.size()-1, nums, x);
            if(j >= 0) {
                ind1 = i; 
                ind2 = j;
                break;
            }
        }
        
        for(int i=0; i<orignal.size(); i++) {
            if(orignal[i] == nums[ind1])
                ans.push_back(i);
            else if(orignal[i] == nums[ind2])
                ans.push_back(i);
        }
        
        return ans;
    }
};