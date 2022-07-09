// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Detail {
    public:
    string chain;
    int opr;
    
    Detail(int _o, string _c) {
        opr = _o;
        chain = _c;
    }
};

class Solution{
public:
    Detail *dp[27][27];
    
    Detail* solve(int i, int j, int arr[]) {
        if(i == j) {
            string curr = "";
            curr += ('A' + i -1);
            return new Detail(0, curr);
        }
        
        if(dp[i][j]->chain != "") return dp[i][j];
        
        int res = INT_MAX;
        string curr = "";
        for(int k=i; k<j; k++) {
            Detail *left = solve(i,k,arr);
            Detail *right = solve(k+1, j, arr);
            int cost = arr[i-1]*arr[k]*arr[j] + left->opr + right->opr;
            
            if(cost < res) {
                curr = "(" + left->chain + right->chain + ")";
                res = cost;
            }
        }
        
        return dp[i][j] = new Detail(res, curr);
    }
    
    string matrixChainOrder(int p[], int n){
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dp[i][j] = new Detail(0, "");
            }
        }       
        
        return solve(1, n-1, p)->chain;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends