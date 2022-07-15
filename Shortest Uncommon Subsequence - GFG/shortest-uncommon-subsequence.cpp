// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
      if(i >= s.size()) return 1000;
      if(j >= t.size()) return 1;
      if(dp[i][j] != -1) return dp[i][j];
      
      int k = j;
      for(; k<t.size(); k++) {
          if(s[i] == t[k]) break;
      }
      
      if(k == t.size()) return 1;
      
      return dp[i][j] = min(f(i+1, j, s, t, dp), 1 + f(i+1, k+1, s, t, dp));
  }
  
    int shortestUnSub(string s, string t) {
        if(s == t) return -1;
        
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        int ans = f(0, 0, s, t, dp);
        if(ans >= 1000) return -1;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends