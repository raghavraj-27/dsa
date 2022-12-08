class Solution {
public:
    vector<int> generateIthRow(int n) {
        vector<int> v(n, 1);
        int res = 1;
        for(int i=0; i<n-2; i++) {
            res *= (n-i-1);
            res /= (i+1);
            
            v[i+1] = res;
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