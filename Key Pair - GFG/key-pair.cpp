// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	int bs(int low, int high, int arr[], int target) {
	    if(high < low) return -1;
	    
	    int mid = (low + high) >> 1;
	    if(arr[mid] < target) {
	        return bs(mid+1, high, arr, target);
	    }
	    if(arr[mid] > target) {
	        return bs(low, mid-1, arr, target);
	    }
	    
	    return mid;
	}
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    sort(arr, arr + n);
	    for(int i=0; i<n; i++) {
	        int target = x - arr[i];
	        int ind = bs(i+1, n-1, arr, target);
	        if(ind != -1) {
	            return true;
	        }
	    }
	    
	    return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
  // } Driver Code Ends