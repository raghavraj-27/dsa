class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0, n = nums.size();
        vector<long long> v;
        
        while(i < n) {
            int j = i, cnt = 0;
            while(j < n and nums[j] == 0) {
                cnt++;
                j++;
            }
            
            if(cnt == 0) {
                i++;
                continue;
            }
            v.push_back(cnt);
            i = j;
        }
        
        long long ans = 0;
        for(int i=0; i<v.size(); i++) {
            ans += (long long) (v[i] * (v[i]+1)) / 2ll;
        }
        
        return ans;
    }
};