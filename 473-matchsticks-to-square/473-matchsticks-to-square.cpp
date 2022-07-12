class Solution {
public:
    bool check(int ind, int sum, int target, vector<int>& nums, vector<bool>& vis, int cnt, int k) {
        if(cnt == k) return true;
        if(sum > target) return false;
        
        if(sum == target) {
            return check(0, 0, target, nums, vis, cnt+1, k);
        }
        
        for(int i=ind; i<nums.size(); i++) {
            if(vis[i] == false) {
                vis[i] = true;
                if(check(i+1, sum+nums[i], target, nums, vis, cnt, k)) return true;
                vis[i] = false;
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& m) {
        int sum = accumulate(m.begin(), m.end(), 0);
        if(sum % 4) return false;
        
        int target = sum / 4;
        vector<bool> vis(m.size(), false);
        bool res = check(0, 0, target, m, vis, 0, 4);
        if(not res) return false;
        
        for(int i=0; i<m.size(); i++) {
            if(vis[i] == false) return false;
        }
        
        return true;
    }
};