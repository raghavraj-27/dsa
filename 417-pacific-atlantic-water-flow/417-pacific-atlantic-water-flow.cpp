class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& vis, vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        
        while(not q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            vis[x][y] = true;
            
            
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < m and nx >= 0 and ny<n and ny>=0 and vis[nx][ny] == false and h[nx][ny] >= h[x][y]) {
                    q.push({nx, ny});
                    
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        // q1-pacific border , q2-atlantic border
        queue<pair<int, int>> q1, q2;
        int m = h.size(), n = h[0].size();
        // pacific
        vector<vector<bool>> v1(m, vector<bool>(n, false)); 
        // atlantic
        vector<vector<bool>> v2(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            q2.push({i, n-1});
            q1.push({i, 0});
            // v1[i][0] = true;
            // v2[i][n-1] = true;
        }
        for(int i=0; i<n; i++) {
            q1.push({0, i});
            q2.push({m-1, i});
            // v1[0][i] = true;
            // v2[m-1][i] = true;
        }
        

        bfs(q1, v1, h);
        bfs(q2, v2, h);
        
        vector<vector<int>> ans;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(v1[i][j] and v2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};