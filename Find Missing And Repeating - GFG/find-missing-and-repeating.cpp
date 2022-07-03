// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        long long s = ((long long)(1LL*n*(n+1))) / 2;
        long long s2 = ((long long)(1LL*n*(n+1)*(2*n+1))) / 6;
        
        long long S = 0, S2 = 0;
        for(int i=0; i<n; i++) {
            S += arr[i];
            S2 += ((long long)(1LL*arr[i]*arr[i]));
        }
        
        long long val1 = S - s;
        long long val2 = S2 - s2;
        long long val3 = val2 / val1;
        
        long long ans1 = (val1 + val3) / 2;
        long long ans2 = ans1 - val1;
        
        int *ans = new int[2];
        for(int i=0; i<n; i++) {
            if(arr[i] == ans1) {
                ans[0] = ans1; 
                ans[1] = ans2;
                return ans;
            }
        }
        
        ans[0] = ans2; 
        ans[1] = ans1;
        
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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends