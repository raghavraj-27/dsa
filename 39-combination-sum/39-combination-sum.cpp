class Solution {
public:
    set<vector<int>> ans;
    void func(int i, vector<int>& v, vector<int>& candidates, int target) {
        if(target < 0 or i>=candidates.size()) return;
        
        if(target == 0) {
            ans.insert(v);
            return;
        }
        
        v.push_back(candidates[i]);
        func(i, v, candidates, target - candidates[i]);
        v.pop_back();
        func(i+1, v, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        func(0, v, candidates, target);
        return vector(ans.begin(), ans.end());
    }
};