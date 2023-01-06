class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<vector<char>> mat(numRows, vector<char> (n, ' '));
        
        int i = 0, x = 0, y = 0;
        
        while(i < s.size()) {
            for(int p=0; p<numRows and i<n; p++) {
                mat[p][y] = s[i++];
            }
            y += 1;
            for(int p=numRows-2; p>0 and i<n; p--) {
                mat[p][y++] = s[i++];
            }
        }
        
        string ans = "";
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] != ' ') {
                    ans += mat[i][j];
                }
            }
        }
        return ans;
    }
};