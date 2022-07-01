// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<long long int>> multiply(vector<vector<long long int>> a, vector<vector<long long int>> b) {
        int n = a.size();
        vector<vector<long long int>> ans(2, vector<long long int> (2, 0));
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                for(int k=0; k<2; k++) {
                    ans[i][j] += (a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return ans;
    }

    vector<vector<long long int>> matrixExponentiate(vector<vector<long long int>> A, int k) {
        if(k == 0) {
            // vector<vector<int>> ans(2, vector<int> (2, 0));
            // ans[0][0] = ans[1][1] = 1;
            vector<vector<long long int>> ans = {{1,0},{0,1}};
            return ans;
        }
        
        if(k == 1) {
            // vector<vector<int>> ans(2, vector<int> (2));
            // ans[0][0] = ans[0][1] = ans[1][0] = 1;
            // ans[1][1] = 0;
            // return ans;
            return A;
        }
        
        vector<vector<long long int>> temp = matrixExponentiate(A, k/2);
        vector<vector<long long int>> ans = multiply(temp, temp);
        
        if(k & 1)
           ans = multiply(ans, A);
           
        return ans;    
    }

    int FindNthTerm(long long int n) {
        
        vector<vector<long long int>> A = {{1,1},{1,0}};
        // A[1][1] = 0;
        
        vector<vector<long long int>> B = matrixExponentiate(A, n);
        // A[0][0] = B[0][0] + B[0][1];
        
        
        
        return B[0][0] % mod;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends