class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> myGrid = grid;
        vector<int> rowMax(n), colMax(n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[i] = max(colMax[i], grid[j][i]);
            }
        }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         colMax[i] = max(colMax[i], grid[j][i]);
        //     }
        // }
        // cout<<"Row Max - \n";
        // for(int i=0; i<n; i++) cout<<rowMax[i]<<"\n";
        // cout<<"\nCol Max - \n";
        // for(int i=0; i<n; i++) cout<<colMax[i]<< " ";
        // cout<<"\n";
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(myGrid[i][j] == rowMax[i] or myGrid[i][j] == colMax[j]) continue;
                myGrid[i][j] = min(rowMax[i], colMax[j]);
                
                
            }
            
        }
        
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                // cout<<myGrid[i][j]<<" ";
                ans += myGrid[i][j] - grid[i][j];
            }
            // cout<<"\n";
        }
        
        return ans;
    }
};