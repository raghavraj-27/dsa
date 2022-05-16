class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        queue<vector<int>> q;
        q.push({0,0,1});
        
        int n = grid.size();
        
        vector<vector<int>> dir = {{-1,-1}, {-1,0}, {-1,+1}, {0,-1}, {0,+1}, {1,-1}, {1,0}, {1,1}};
        while(q.empty() == false) {
            int sz = q.size(); 
            while(sz--) {
                vector<int> point = q.front(); 
                q.pop();
                
                int r = point[0];
                int c = point[1];
                int curr_moves = point[2];
                
                if(r == n-1 and c == n-1) {
                    return curr_moves;
                }
                
                for(int i=0; i<dir.size(); i++) {
                    int x = r + dir[i][0];
                    int y = c + dir[i][1];
                    
                    if(x >= 0 and y>=0 and x<n and y<n and grid[x][y] == 0) {
                        q.push({x, y, curr_moves + 1});
                        grid[x][y] = 1;
                    }
                }
            }
        }
        
        return -1;
    }
};