class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int target) {
        int n = a.size(), m = a[0].size(); 
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=1; j<m; j++) {
                a[i][j] += a[i][j-1];
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=i; j<m; j++) {
                int sum = 0;
                unordered_map<int, int> mp;
                mp[0] = 1;
                for(int k=0; k<n; k++) {
                    sum += a[k][j] - (i > 0 ? a[k][i-1] : 0);
                    ans += (mp.find(sum - target) != mp.end() ? mp[sum - target] : 0);
                    mp[sum]++;
                }
            }
        }
        
        return ans;
    }
};