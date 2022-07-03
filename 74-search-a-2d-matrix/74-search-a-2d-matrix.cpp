class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int X) {
        int M = matrix[0].size(), N = matrix.size();
        int i = N-1;
	    int j = 0;
	    
	    while(i >= 0 and j >= 0 and i<N and j<M) {
	        int curr = matrix[i][j];
	        if(curr == X) return 1;
	        
	        if(curr < X) j++;
	        else i--;
	    }
	    
	    return 0;
    }
};