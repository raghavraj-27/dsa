class Solution {
public:
    vector<vector<int>> ans;
    void f(int ind, vector<int>& c, vector<int>& temp, int target) {
        if(target == 0) {
            ans.push_back(temp);
        }
        
        for(int i=ind; i<c.size(); i++) {
            if(i != ind and c[i] == c[i-1]) continue;
            
            if(c[i] <= target) {
                temp.push_back(c[i]);
                f(i+1, c, temp, target-c[i]);
                temp.pop_back();
            } else {
                return;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        
        f(0, candidates, temp, target);
        return ans;
    }
};