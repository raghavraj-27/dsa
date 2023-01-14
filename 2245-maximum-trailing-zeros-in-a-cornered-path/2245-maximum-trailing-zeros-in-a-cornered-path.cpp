class Solution {
public:
    int m, n;
    pair<int, int> add(pair<int, int> p1, pair<int, int> p2) {
        return make_pair(p1.first + p2.first, p1.second + p2.second);
    }
    pair<int, int> sub(pair<int, int> p1, pair<int, int> p2) {
        return make_pair(p1.first - p2.first, p1.second - p2.second);
    }
    
    void fill(vector<vector<pair<int, int>>>& mat, vector<vector<int>>& grid) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int num = grid[i][j];
                int cnt2 = 0, cnt5 = 0;
                
                while(num%2 == 0) {
                    num /= 2; cnt2++;
                }
                while(num%5 == 0) {
                    num /= 5; cnt5++;
                }
                
                mat[i][j] = make_pair(cnt2, cnt5);
            }
        }
    }
    void createPrefix(vector<vector<pair<int, int>>>& mat, vector<vector<pair<int, int>>>& pre) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                pre[i][j] = add(mat[i][j], (j>0 ? pre[i][j-1] : make_pair(0, 0)));
            }
        }
    }
    int maxTrailingZeros(vector<vector<int>>& grid) {
        // int ans;
        m = grid.size(), n = grid[0].size();
        vector<vector<pair<int, int>>> mat(m, vector<pair<int, int>> (n));
        
        fill(mat, grid);
        vector<vector<pair<int, int>>> pre(m, vector<pair<int, int>> (n));
        // vector<vector<pair<int, int>>> suf(m, vector<pair<int, int>> (n));
        createPrefix(mat, pre);
        // createSuffix(mat, suf);
        
        int ans = 0;
        for(int j=0; j<n; j++) {
            pair<int, int> prevSum = {0, 0};
            for(int i=0; i<m; i++) {
                pair<int, int> pl, pr;
                if(j == 0) {
                    pl = add(prevSum, pre[i][n-1]);
                    ans = max(ans, min(pl.first, pl.second));
                } else {
                    pl = add(prevSum, sub(pre[i][n-1], pre[i][j-1]));
                    ans = max(ans, min(pl.first, pl.second));
                    
                    pr = add(prevSum, pre[i][j]);
                    ans = max(ans, min(pr.first, pr.second)); 
                }
                prevSum = add(prevSum, mat[i][j]);
            }
        }
        
        for(int j=0; j<n; j++) {
            pair<int, int> prevSum = {0, 0};
            for(int i=m-1; i>=0; i--) {
                pair<int, int> pl, pr;
                if(j == 0) {
                    pl = add(prevSum, pre[i][n-1]);
                    ans = max(ans, min(pl.first, pl.second));
                } else {
                    pl = add(prevSum, sub(pre[i][n-1], pre[i][j-1]));
                    ans = max(ans, min(pl.first, pl.second));
                    
                    pr = add(prevSum, pre[i][j]);
                    ans = max(ans, min(pr.first, pr.second)); 
                }
                prevSum = add(prevSum, mat[i][j]);
            }
        }
        
        return ans;
    }
};