class Solution {
public:
    int extractSum(int i, int j, vector<vector<int>>& sum) {
        if(i < 0) return 0;
        if(j < 0) return 0;
        if(i >= sum.size()) i = sum.size()-1;
        if(j >= sum[0].size()) j = sum[0].size()-1;
        return sum[i][j];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> prefix(m, vector<int> (n, 0));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                prefix[i][j] = mat[i][j] + extractSum(i, j-1, prefix) + extractSum(i-1, j, prefix) - extractSum(i-1, j-1, prefix);
            }
        }
        
        vector<vector<int>> ans(m, vector<int> (n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans[i][j] = (extractSum(i+k, j+k, prefix) - extractSum(i+k, j-k-1, prefix)) - (extractSum(i-k-1, j+k, prefix) - extractSum(i-k-1, j-k-1, prefix));
            }
        }
        
        return ans;
    }
};