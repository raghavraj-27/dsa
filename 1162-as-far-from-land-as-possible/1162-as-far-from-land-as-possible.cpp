class Solution {
public:
    // void bfs(queue<pair<int, int>>& q, int i, int j, vector<vector<int>>& grid, int n) {
    //     grid[i][j] = 1;
    //     bfs(i-1, j, grid)
    // }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(); 
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) q.push({i, j});
            }
        }
        
        if(q.size() == 0 or q.size() == n*n) return -1;
        int cnt = 0;
        
        while(q.empty() == false) {
            int sz = q.size();
            
            while(sz--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                // bfs(q, i, j, grid, n);
                if(i > 0 and grid[i-1][j] == 0) {
                    grid[i-1][j] = 1;
                    q.push({i-1, j});
                }
                if(i < n-1 and grid[i+1][j] == 0) {
                    grid[i+1][j] = 1;
                    q.push({i+1, j});
                }
                if(j > 0 and grid[i][j-1] == 0) {
                    grid[i][j-1] = 1;
                    q.push({i, j-1});
                }
                if(j < n-1 and grid[i][j+1] == 0) {
                    grid[i][j+1] = 1;
                    q.push({i, j+1});
                }
            }
            cnt++;
        }
        
        return cnt-1;
    }
};