class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> weekrows;
        for(int i=0; i<mat.size(); i++) {
            int val = accumulate(mat[i].begin(), mat[i].end(), 0);
            weekrows.push_back({val, i});
        }
        
        sort(weekrows.begin(), weekrows.end());
        
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(weekrows[i].second);
        }
        
        return ans;
    }
};