class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int totalMin = 0, freshOrange = 0;
        queue<pair<int, int>> q;
        
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    freshOrange++;
                }
            }
        }
        
        if(q.size() == 0 and freshOrange != 0) return -1;
        if(q.size() == 0) return 0;
        
        while(not q.empty()) {
            int sz = q.size();
            totalMin++;
            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop(); 

                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        freshOrange--;
                    }
                }
            }
        }
        
        if(freshOrange > 0) return -1;
        return totalMin-1;
    }
};