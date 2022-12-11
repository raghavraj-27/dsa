// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, int N, vector<vector<int>>& m, string d, vector<string>& ans) {
        if(i >= N or j >= N or i<0 or j<0) return;
        if(m[i][j] == 0 or m[i][j] == -1) return;
        
        if(i == N-1 and j == N-1) {
            ans.push_back(d);
            return;
        }
        
        m[i][j] = -1;
        solve(i+1, j, N, m, d + "D", ans);
        solve(i, j+1, N, m, d + "R", ans);
        solve(i, j-1, N, m, d + "L", ans);
        solve(i-1, j, N, m, d + "U", ans);
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string d = "";
        
        solve(0, 0, n, m, d, ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends