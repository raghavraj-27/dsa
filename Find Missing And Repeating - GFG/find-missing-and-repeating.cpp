// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        long sum=0,sum2=0;
        for(int i=0;i<n;i++){
            sum+=(arr[i]-(i+1));
            sum2+=(1LL*arr[i]*arr[i] - 1LL*(i+1)*(i+1));
        }
        //sum2 = a*a-b*b = (a-b)(a+b) = (sum)(a+b)
        //sum2/sum = a+b
        //sum = a-b
        //hence
        ans[0] =  (sum2/sum + sum) / 2;
        ans[1] =  (sum2/sum - sum) / 2;
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