class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> store;
        for(int val: nums) store.insert(val);
        if(store.size() == 0) return 0;
        
        int ans = 1;
        for(int i=0; i<nums.size(); i++) {
            int val = nums[i];
            
            if(store.find(val-1) == store.end()) {
                int cnt = 0;
                while(store.find(val) != store.end()) {
                    cnt++;
                    val++;
                }
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
};