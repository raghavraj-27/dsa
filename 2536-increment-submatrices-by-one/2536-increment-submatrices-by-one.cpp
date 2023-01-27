class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> a(n, vector<int> (n, 0));
        
        for(auto v: q) {
            int r1 = v[0], c1 = v[1];
            int r2 = v[2], c2 = v[3];
            
            a[r1][c1]++;
            
            if(c2+1 < n) {
                a[r1][c2+1]--;
                // a[r2][c2+1]--;
            }
            if(r2+1 < n) {
                a[r2+1][c1]--;
                // a[r2+1][c2]--;
            }
            if(r2+1 < n and c2+1 < n) a[r2+1][c2+1]++;
        }
        
        for(int i=0; i<n; i++) {
            for(int j=1; j<n; j++) {
                a[i][j] += a[i][j-1];
            }
        }
        
        for(int j=0; j<n; j++) {
            for(int i=1; i<n; i++) {
                a[i][j] += a[i-1][j];
            }
        }
        
        return a;
    }
};