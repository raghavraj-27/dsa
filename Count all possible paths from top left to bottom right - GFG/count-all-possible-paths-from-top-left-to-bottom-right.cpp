// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    public:
  int dp[100][100];
 int  solve(int x,int y,int m,int n){
      if(x==m-1&&y==n-1)return 1;
      if(x<0||y<0||x>=m||y>=n)return 0;
      if(dp[x][y]!=-1)return dp[x][y];
      return dp[x][y]=(solve(x+1,y,m,n)%1000000007+solve(x,y+1,m,n)%1000000007)%1000000007;
   
  }
    long long int numberOfPaths(int m, int n){
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends