class Solution {
public:
//     int row, col;
//     int memo[51][51];
//     int pass(vector<vector<int>> &m, int i, int j, vector<vector<int>> &Cost)
//     {
//         if (i == row - 1 and (j >= 0 and j <= col - 1))
//             return m[i][j];
//         if (i == row || (j < 0 || j == col))
//             return 6000;   // taking max =6000 according to constraints
//         if (memo[i][j] != -1)
//             return memo[i][j];
//         int ans = 6000;
//         for (int ii = 0; ii < col; ii++)   
//         {
//             ans = min(ans, (m[i][j] + Cost[m[i][j]][ii] + pass(m, i + 1, ii, Cost)));
//         }
//         return memo[i][j] = ans;
//     }
//     int minPathCost(vector<vector<int>> &matrix, vector<vector<int>> &moveCost)
//     {
//         int ans = INT_MAX;
//         memset(memo, -1, sizeof(memo));
//         row = matrix.size();
//         col = matrix[0].size();
//         for (int i = 0; i < col; i++)
//         {
// 		     // as we have to start from first row so we call for (0,0)  (0,1)  (0,2) ....
//             ans = min(ans, pass(matrix, 0, i, moveCost));
			
//         }
//         return ans;
//     }
//     int minCost(int i, int j, int cost, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp) {
//         if(i >= grid.size()) {
//             return 100000;
//         }
        
//         if(i == grid.size() - 1) {
//             return cost + grid[i][j];
//         }
        
//         if(dp[i][j] != -1) {
//             return dp[i][j];
//         }
        
//         int sub_ans = INT_MAX;
//         for(int p=0; p<grid[0].size(); p++) {
//             int c = grid[i][j] + minCost(i+1, p, cost + moveCost[grid[i][j]][p], grid, moveCost, dp);
//             sub_ans = min(c, sub_ans);
//         }
        
//         return dp[i][j] = sub_ans;
//     }
//     int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
//         int ans = INT_MAX;
        
//         vector<vector<int>> dp(51, vector<int> (51, -1));
        
//         for(int i=0; i<grid[0].size(); i++) {
//             ans = min(ans, minCost(0, i, 0, grid, moveCost, dp));
//         }
        
//         return ans;
//     }
    
    int minPathCost(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp) {
            if(i >= m or j>= n) return 100000;
            
            if(dp[i][j] != -1) {
                return dp[i][j];
            }
            if(i == m-1) {
                return grid[i][j];
            }

            int minCost = INT_MAX;
            for(int p=0; p<n; p++) {
                int cost = grid[i][j] + moveCost[grid[i][j]][p] + minPathCost(i+1, p, m, n, grid, moveCost, dp);
                minCost = min(cost, minCost);
            }

            return dp[i][j] = minCost;
        }

        int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
            int m = grid.size(), n = grid[0].size(); 
            int ans = INT_MAX;
        
            vector<vector<int>> dp(51, vector<int> (51, -1));

            for(int i=0; i<grid[0].size(); i++) {
                ans = min(ans, minPathCost(0, i, m, n, grid, moveCost, dp));
            }

            return ans;
        }
};