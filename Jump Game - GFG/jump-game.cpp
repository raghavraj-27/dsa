// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        if(A[0] == 0) return 0; 
        if(N == 1) return 1;
        
        int currdist = A[0];
        int farthest = A[0];
        int ans = 1;
        for(int i=1; i<N; i++) {
            if(A[i] + i > farthest) {
                farthest = A[i] + i;
            }
            
            if(i == currdist) {
                currdist = farthest;
                if(farthest < N-1 and A[farthest] == 0) ans = 0;
                else ans = 1;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends