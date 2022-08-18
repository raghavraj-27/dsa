class Solution {
public:
    long long nCr(int n, int r) {
        long long ans = 1;
        for(int i=1; i<=r; i++) {
            ans = ans * (n-r+i) / i;
            cout<<"T-"<<(n-r+i)<<endl;
        }
        return ans;
    }
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        long long good_pairs = 0;
        
        for(int i=n-2; i>=0; i--) {
            int val_i = i - nums[i];
            mp[i+1 - nums[i+1]]++;
            cout<<mp[i+1 - nums[i+1]]<<endl;
            
            if(mp.find(val_i) != mp.end()) {
                good_pairs += mp[val_i];
            }
        }
        
        long long total_pairs = nCr(n, 2);
        return total_pairs - good_pairs;
    }
};