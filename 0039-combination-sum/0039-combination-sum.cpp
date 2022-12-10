class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void f(int i, int N, vector<int>& c, int sum, int target) {
        if(sum == target) {
            ans.push_back(v);
            return;
        }
        
        if(i >= N or sum > target) return;
        
        v.push_back(c[i]);
        f(i, N, c, sum + c[i], target);
        
        v.pop_back();
        f(i+1, N, c, sum, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(0, candidates.size(), candidates, 0, target);
        return ans;    
    }
};