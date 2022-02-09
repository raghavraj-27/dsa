class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
        }
        
        int cnt = 0;
        for(auto p : mp) {
            if(k==0 and p.second>1) {
                cnt++;
            } else if(k!=0 and mp.count(p.first + k)>0) {
                cnt++;
            }
        }
        
        return cnt;
    }
};