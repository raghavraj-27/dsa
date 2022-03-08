class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> s;
        for(auto val : nums) {
            s.insert(val);
        }
        
        long long ans = (long long)k*(long long)(k+1) / 2ll;
        for(auto val : s) {
            if(val <=k) {
                ans -= val;
                k++;
                ans += k;
            }
        }
        
        return ans;
    }
};