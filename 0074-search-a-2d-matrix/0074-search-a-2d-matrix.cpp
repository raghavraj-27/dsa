class Solution {
public:
    int row, col;
    
    bool search(int start, int end, vector<vector<int>>& mat, int target) {
        if(start > end) return false;
        
        int mid = (start + end) / 2;
        int r = mid / col;
        int c = mid % col;
        
        if(mat[r][c] < target) return search(mid+1, end, mat, target);
        if(mat[r][c] > target) return search(start, mid-1, mat, target);
        
        return true;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        row = matrix.size(), col = matrix[0].size();
        return search(0, row*col-1, matrix, target);
    }
};