class Solution {
public:
    bool isPossible(long long maxQuan, vector<int>& nums, int maxBag) {
        long long cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            cnt += nums[i]/maxQuan;
            if(nums[i]%maxQuan)
                cnt++;
        }
        if(cnt > maxBag)
            return false;
        return true;
    }
    
    int minimumSize(vector<int>& nums, int maxOpr) {
        int maxBag = nums.size() + maxOpr;
        // long long low = 1, high = accumulate(nums.begin(), nums.end(), 0);        
        long long low = 1, high = 1e9;

        long long res = -1; 
        
        while(low <= high) {
            long long mid = (low + high) >> 1; 
            
            if(isPossible(mid, nums, maxBag)) {
                res = mid; 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return res;
    }
};