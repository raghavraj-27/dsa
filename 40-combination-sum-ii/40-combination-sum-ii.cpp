class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int>& candidates, int target, vector<int>& subsets) {
        if(target == 0) {
            ans.push_back(subsets);
            return;
        }
        
        if(ind >= candidates.size() or target < 0) return;
        
        for(int i=ind; i<candidates.size(); i++) {
            if(ind != i and candidates[i-1] == candidates[i]) continue;
            subsets.push_back(candidates[i]);
            solve(i+1, candidates, target-candidates[i], subsets);
            subsets.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subsets;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, subsets);
        
        return ans;
    }
};