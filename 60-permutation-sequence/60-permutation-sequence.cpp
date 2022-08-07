class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        string nums = "";
        for(int i=1; i<n; i++) {
            fact *= i;
            nums = nums + to_string(i);
        }
        nums = nums + to_string(n);
        
        k--;
        string ans = "";
        while(true) {
            ans = ans + nums[k / fact];
            
            
            
            nums.erase(nums.begin() + k/fact);
            if(nums.size() == 0) break;
            k = k % fact;
            fact /= nums.size();
            
            
        }
        
        return ans;
    }
};