class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& o) {
        vector<int> ans(nums.size());
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]] = i;
        }
        
        for(int i=0; i<o.size(); i++) {
            if(mp.find(o[i][0]) != mp.end()) {
                int ind = mp[o[i][0]];
                mp[o[i][1]] = ind;
                mp.erase(o[i][0]);
            }
        }
        
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            ans[it->second] = it->first;
        }
        
        return ans;
    }
};