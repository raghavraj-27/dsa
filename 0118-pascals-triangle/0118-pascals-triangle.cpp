class Solution {
public:
    vector<int> generateIthRow(int n) {
        vector<int> v;
        
        for(int i=0; i<n; i++) {
            int N = n-1;
            int r = i;
            int res = 1;
            for(int j=1; j<=r; j++) {
                res = res * (N-r+j) / j;
            }
            v.push_back(res);
        }
        
        return v;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++) {
            ans.push_back(generateIthRow(i+1));
        }
        
        return ans;
    }
};