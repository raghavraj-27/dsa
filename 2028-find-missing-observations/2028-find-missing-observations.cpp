class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum_m = 0, m = rolls.size();
        for(auto val : rolls) {
            sum_m += val;
        }
        
        int sum_n = (mean*(n+m)) - sum_m;
        
        vector<int> ans;
        if(sum_n > 6*n) return ans;
        if(sum_n < n) return ans;
        
        int val = sum_n / n;
        for(int i=0; i<n; i++) 
            ans.push_back(val);
        int rem = sum_n % n;
        for(int i=0; i<rem; i++) 
            ans[i] += 1;
        
        return ans;
    }
};