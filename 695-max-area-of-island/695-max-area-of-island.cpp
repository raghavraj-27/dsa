class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size()) return 0;
        if(grid[i][j] == 0) return 0;
        
        int cnt = grid[i][j];
        grid[i][j] = 0;
        cnt += dfs(i+1, j, grid);
        cnt += dfs(i-1, j, grid);
        cnt += dfs(i, j+1, grid);
        cnt += dfs(i, j-1, grid);
        
//         for(int p=0; p<4; p++) {
//             int x = i + dx[p];
//             int y = j + dy[p];
            
//             cnt += dfs(x, y, grid);
//             grid[x][y] = 0;
//         }
        
        
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // vector<vector<int>> vis(m, vector<int> (n, false));
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};