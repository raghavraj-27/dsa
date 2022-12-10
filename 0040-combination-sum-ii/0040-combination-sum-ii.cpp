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
        
        for(int ind=i; ind<c.size(); ind++) {
            if(ind!=i and c[ind] == c[ind-1]) continue;
            v.push_back(c[ind]);
            f(ind+1, N, c, sum + c[ind], target);
            v.pop_back();
            // f(ind+1, N, c, sum, target);
        }
        // v.push_back(c[i]);
        // f(i+1, N, c, sum + c[i], target);
        // v.pop_back();
        // f(i+1, N, c, sum, target);
    } 
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        f(0, candidates.size(), candidates, 0, target);
        return ans;
    }
};