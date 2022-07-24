class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n = matrix[0].size(); 
        int i = m-1, j = 0;
        
        while(i < m and j < n and i >= 0 and  j >= 0) {
            if(matrix[i][j] == target) return true;
            
            if(matrix[i][j] > target) i--;
            else j++;
        }
        
        return false;
    }
};