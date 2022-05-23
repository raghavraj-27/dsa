class Solution {
public:
    int dp[601][101][101] = {0};
    int count(string & str) {
        int c = 0; 
        for(int i=0; i<str.size(); i++) {
            if(str.at(i) == '0'){
                c++;
            }
        }
        return c;
    }
    
    int calc(int i, vector<string> & v, int zero, int one, unordered_map<string, int>& count0) {
        if(i == v.size() or one + zero == 0) {
            return 0;
        }
        
        // string str = to_string(zero) + "," + to_string(one) + "," + to_string(i);
        if(dp[i][zero][one] > 0) return dp[i][zero][one];
        
        // if(dp.find(str) != dp.end()) {
        //     return dp[str];
        // }
        
        int c0 = count0[v[i]];
        int c1 = v[i].size() - c0;
        
        int consider = 0; 
        if(c0<=zero and c1<=one) {
            consider = 1 + calc(i+1, v, zero - c0, one - c1, count0);
        }
        
        int skip = calc(i+1, v, zero, one, count0); 
        
        return dp[i][zero][one] = max(consider, skip); 
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<string, int> dp;
        // int dp[strs.size()+1][m+1][n+1];
        // memset(dp, 0, sizeof(dp));
        
        unordered_map<string, int> count0;
        
        for(int i=0; i<strs.size(); i++) {
            if(count0.find(strs[i]) == count0.end()) {
                int cnt = 0;
                for(int j=0; j<strs[i].size(); j++) {
                    if(strs[i][j] == '0') cnt++;
                }
                count0[strs[i]] = cnt;
            }
            
        }
        
        return calc(0, strs, m, n, count0);
    }
    
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int len = strs.size();
//         int dp[len+1][m+1][n+1];
//         memset(dp, 0, sizeof dp);
        
//         for (int i=1;i<=len;i++){
//             for (int j=0;j<=m;j++){
//                 for (int k=0;k<=n;k++){
//                     int ones = count(strs[i-1].begin(), strs[i-1].end(), '1');
//                     int zeros = strs[i-1].size()-ones;
//                     int res = dp[i-1][j][k];
//                     if (zeros<=j && ones<=k) 
//                        res = max(res, dp[i-1][j-zeros][k-ones]+1);
//                     dp[i][j][k] = res;
//                 }
//             }
//         }
        
//         return dp[len][m][n];
        
//     }
};