class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(); 
        
        // Transpose the matrix [ie : row to col]
        for(int i=0; i<row; i++) {
            for(int j=0; j<i; j++) {
                int temp = matrix[i][j]; 
                matrix[i][j] = matrix[j][i]; 
                matrix[j][i] = temp;
            }
        }
        
        // Reverse each row
        for(int i=0; i<row; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};