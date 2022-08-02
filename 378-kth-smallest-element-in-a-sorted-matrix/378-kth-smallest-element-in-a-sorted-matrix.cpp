class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); 
        int res = 0;
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while(low < high) {
            int mid = (low + high) >> 1;
            
            int cnt = 0;
            for(int i=0; i<n; i++) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); 
            }
            
            if(cnt < k) {
                // res = mid;
                low = mid + 1;
            }
            else high = mid;
        }
        
        return low;
    }
};

// 1  5  9
// 10 11 13
// 12 13 15
    
// 1 5 9 10 11 12 13 13 15