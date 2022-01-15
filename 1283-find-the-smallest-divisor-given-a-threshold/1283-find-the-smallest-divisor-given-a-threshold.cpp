class Solution {
public:
    bool isPossible(int divisor, vector<int>& nums, int threshold)
    {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += ceil((float)nums[i] / divisor);
        }
        
        if(sum > threshold) return false;
        
        return true;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1e6, res = -1; 
        while(low <= high)
        {
            int mid = (low + high) >> 1; 
            
            if(isPossible(mid, nums, threshold)) 
            {
                res = mid; 
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        
        return res;
    }
};