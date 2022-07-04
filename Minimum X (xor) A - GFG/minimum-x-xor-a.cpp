// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int oneInA = __builtin_popcountll(a);
        int oneInB = __builtin_popcountll(b);
        
        if(oneInA == oneInB) return a;
        
        int i=30;
        int ans = 0;
        while(i >= 0 and oneInB > 0) {
            if(a & (1<<i)) {
                ans |= (1<<i);
                oneInB--;
            }
            i--;
        }
        i=0;
        while(oneInB > 0) {
            if(ans & (1<<i)) {
                i++;
                continue;
            }
            ans = ans | (1<<i);
            oneInB--;
            i++;
        }
        
        return ans;
    }
};
// 1001
// 0111

// 10100
// 10011

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends