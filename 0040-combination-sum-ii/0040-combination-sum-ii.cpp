class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void f(int i, int N, vector<int>& c, int sum, int target) {
        if(sum == target) {
            ans.push_back(v);
            return;
        }
        
        for(int ind=i; ind<c.size(); ind++) {
            if(ind!=i and c[ind] == c[ind-1]) continue;
            
            if(sum + c[ind] > target) break;
            
            v.push_back(c[ind]);
            f(ind+1, N, c, sum + c[ind], target);
            v.pop_back();
        }
    } 
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        f(0, candidates.size(), candidates, 0, target);
        return ans;
    }
};