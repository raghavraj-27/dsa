class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long cnt = 0;
        int x = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++) {
            x = x ^ nums[i];
            
            if(x == 0) cnt++;
            
            if(mp.find(x) != mp.end()) {
                cnt += mp[x];
            }
            mp[x]++;
        }
        
        return cnt;
    }
};