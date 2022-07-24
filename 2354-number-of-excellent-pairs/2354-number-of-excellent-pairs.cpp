class Solution {
public:
    int get1s(int num) {
        int cnt = 0;
        while(num > 0) {
            if(num& 1) cnt++;
            num = num >> 1;
        }
        return cnt;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;
        vector<int> v;
        for(int i=0; i<nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = get1s(nums[i]);
                            v.push_back(mp[nums[i]]);

            }
        }
        
        sort(v.begin(), v.end()); 
        for(int i=0; i<v.size(); i++) {
            int ind = lower_bound(v.begin(), v.end(), k-v[i]) - v.begin();
            ans += v.size()-ind;
        }
        
        return ans;
    }
};
// 1 1 1 2
