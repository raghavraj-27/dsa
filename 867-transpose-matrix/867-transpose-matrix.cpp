class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> mat(matrix[0].size(), vector<int> (matrix.size()));
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                mat[i][j] = matrix[j][i];
            }
        }
        return mat;
    }
};