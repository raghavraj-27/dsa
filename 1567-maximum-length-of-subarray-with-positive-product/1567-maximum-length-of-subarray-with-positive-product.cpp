class Solution {
public:
    int calc(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0) cnt++;
        }
        
        if(cnt%2 == 0) return nums.size(); 
        
        int i=0, j=nums.size()-1;
        while(nums[i] >= 0) i++;
        while(nums[j] >= 0) j--;
        
        int val1 = nums.size()-i-1;
        int val2 = j;
        int val3 = j-i-1;
        
        return max({val1, val2, val3});
    }
    int getMaxLen(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                v.push_back(nums[i]);
            } else {
                ans.push_back(v);
                v.clear();
            }
        }
        ans.push_back(v);
        int max_len = 0;
        for(int i=0; i<ans.size(); i++) {
            max_len = max(max_len, calc(ans[i]));
        }
        
        return max_len;
    }
};