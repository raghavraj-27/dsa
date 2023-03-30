class Solution {
public:
    vector<int> v;
    Solution() {
        int n = 1000;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
        for (int p = 2; p <= n; p++) {
            if (prime[p]) {
                v.push_back(p);
            }
        }
    }
    bool isSorted(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        // cout<<v[0]<<"\n";
        int n = nums.size(); 
        for(int i=0; i<n; i++) {
            int prime = 0;
            for(int j=0; v[j] < nums[i] and j < v.size(); j++) {
                if(i == 0) {
                    prime = v[j];
                    // prime = max(prime, v[j]);
                } else {
                    if(v[j] < nums[i] and nums[i] - v[j] > nums[i-1]) {
                        prime = v[j];
                        // prime = max(prime, v[j]);
                    }
                }
            }
            
            int currNum = nums[i] - prime;
            if(i > 0 and nums[i-1] == currNum) continue;
            nums[i] = currNum;
        }
        
        for(int val: nums) cout<<val <<" ";
        
        return isSorted(nums);
    }
};