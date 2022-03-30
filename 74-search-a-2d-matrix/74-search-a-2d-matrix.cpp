class Solution {
public:
    int row, col;
    
    bool search(int left, int right, vector<vector<int>>& matrix, int target) {
        if(right < left)
            return false;
        
        int mid = (left + right) / 2;
        int i = mid / col; 
        int j = mid % col; 
        
        if(matrix[i][j] > target)
            return search(left, mid-1, matrix, target); 
        if(matrix[i][j] < target)
            return search(mid+1, right, matrix, target); 
        
        return true;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        row = matrix.size(); 
        col = matrix[0].size(); 
        
        int left = 0; 
        int right = row*col -1;
        
        return search(left, right, matrix, target);
    }
};