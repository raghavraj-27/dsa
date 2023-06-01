class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> startLeft, startRight;
        for(int i=m-1; i>=0; i--) startLeft.push_back(make_pair(i, 0));
        for(int i=1; i<n; i++) startLeft.push_back(make_pair(0, i));
        
        for(int i=0; i<m; i++) startRight.push_back(make_pair(i, n-1));
        for(int i=n-2; i>=0; i--) startRight.push_back(make_pair(m-1, i));
        
        vector<vector<int>> prefixGrid(m, vector<int> (n, 0));
        for(int i=0; i<startLeft.size(); i++) {
            int x = startLeft[i].first, y = startLeft[i].second;
            
            unordered_set<int> st;
            while(x < m and y < n) {
                st.insert(grid[x][y]);
                prefixGrid[x][y] = st.size();
                
                x++; y++;
            }
        }
        
        vector<vector<int>> suffixGrid(m, vector<int> (n, 0));
        for(int i=0; i<startRight.size(); i++) {
            int x = startRight[i].first, y = startRight[i].second;
            
            unordered_set<int> st;
            while(x >=0 and y >=0) {
                st.insert(grid[x][y]);
                suffixGrid[x][y] = st.size();
                
                x--; y--;
            }
        }
        
        vector<vector<int>> ans(m, vector<int> (n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int p = 0;
                int s = 0;
                
                if(i > 0 and j > 0) p = prefixGrid[i-1][j-1];
                if(i < m-1 and j < n-1) s = suffixGrid[i+1][j+1];
                ans[i][j] = abs(p - s);
            }
        }
        
        return ans;
    }
};