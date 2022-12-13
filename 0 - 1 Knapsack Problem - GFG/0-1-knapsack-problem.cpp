//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int i, int wt[], int val[], int capacity, vector<vector<int>>& dp) {
        if(i < 0) return 0;
        
        if(dp[i][capacity] != -1) return dp[i][capacity];
        
        int notTake = f(i-1, wt, val, capacity, dp);
        int take = INT_MIN;
        if(capacity >= wt[i]) {
            take = val[i] + f(i-1, wt, val, capacity - wt[i], dp);
        }
        
        return dp[i][capacity] = max(take, notTake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {
        
        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return f(n-1, wt, val, W, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends