class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // if(ops.size() == 0) return m * n;
        int minRow = m, minCol = n;
        
//         for(int i=0; i<ops.size(); i++) {
            
//         }
//         sort(ops.begin(), ops.end());
        
        for(auto it: ops) {
            minRow = min(minRow, it[0]);
            minCol = min(minCol, it[1]);
            // cout<<"["<<it[0]<<", "<<it[1]<<"]\n";
        }
        
        return minRow * minCol;
    }
};