class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            if(grid[i][0] == 0) {
                for(int j=0; j<n; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        for(int i=1; i<n; i++) {
            int sum = 0;
            for(int j=0; j<m; j++) {
                sum += grid[j][i];
            }
            
            if(sum <= m/2) {
                for(int j=0; j<m; j++) {
                    grid[j][i] = !grid[j][i];
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<m; i++) {
            int num = 0;
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    num |= 1<<(n-1-j);
                }
            }
            
            ans += num;
        }
        
        return ans;
    }
};