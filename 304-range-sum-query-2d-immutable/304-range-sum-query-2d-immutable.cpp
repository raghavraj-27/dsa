class NumMatrix {
public:
    vector<vector<int>> sum;
    int extractSum(int i, int j, vector<vector<int>>& sum) {
        if(i < 0) return 0;
        if(j < 0) return 0;
        if(i >= sum.size()) i = sum.size()-1;
        if(j >= sum[0].size()) j = sum[0].size()-1;
        return sum[i][j];
    }
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix(m, vector<int> (n, 0));
        sum = prefix;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                sum[i][j] = matrix[i][j] + extractSum(i-1, j, sum) + extractSum(i, j-1, sum) 
                    - extractSum(i-1, j-1, sum);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = extractSum(row2, col2, sum) - extractSum(row2, col1-1, sum) - 
            (extractSum(row1-1, col2, sum) - extractSum(row1-1, col1-1, sum));
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */