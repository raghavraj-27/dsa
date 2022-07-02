// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<vector<ll>> ans;
        int mod = 1e9 + 7;
        ans.push_back({1ll});
        
        for(int i=1; i<=n; i++) {
            vector<ll> v(i, 1ll);
            for(int j=1; j<v.size()-1; j++) {
                v[j] = (ans[i-1][j] + ans[i-1][j-1]) % mod;
            }
            ans.push_back(v);
        }
        
        return ans[n];
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends