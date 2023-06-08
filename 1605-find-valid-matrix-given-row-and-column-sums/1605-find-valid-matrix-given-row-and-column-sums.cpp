class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int m = row.size(), n = col.size(); 
        vector<vector<int>> ans(m, vector<int> (n));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans[i][j] = min(row[i], col[j]);
                row[i] -= ans[i][j];
                col[j] -= ans[i][j];
            }
        }
        
        return ans;
    }
};