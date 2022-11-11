class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int, int> mp, freq;
        for(int i=0; i<nums.size(); i++) {
            int val = nums[i] % space;
            
            if(mp.find(val) != mp.end()) {
                mp[val] = min(mp[val], nums[i]);
            } else {
                mp[val] = nums[i];
            }
            
            nums[i] = val;
            freq[nums[i]]++;
        }
        
        int mx = INT_MAX, mxcnt = 0;
        for(auto p: freq) {
            if(p.second > mxcnt) {
                mx = mp[p.first];
                mxcnt = p.second;
            } else if(p.second == mxcnt) {
                mx = min(mp[p.first], mx);
            }
        }
        
        return mx;
    }
};