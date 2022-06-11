class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int k = accumulate(nums.begin(), nums.end(), 0) - x;
        if(k < 0) return -1;
        if(k == 0) return nums.size();
        map<int, int> freq;
        int sum = 0, max_len = 0;
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(sum == k) max_len = i + 1;
            if(freq.find(sum) == freq.end()) freq[sum] = i;
            if(freq.find(sum - k) != freq.end()) {
                max_len = max(max_len, i - freq[sum-k]);
            }
        }
        if(max_len == 0) return -1;
        return nums.size() - max_len;
    }
};