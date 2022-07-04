// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int i=0 , n = arr.size();
        while(i < n) {
            int j = i + 1;
            while(j < n) {
                int l = j+1, r = n-1;
                int target = k - arr[i] - arr[j];
                while(l < r) {
                    if(arr[l] + arr[r] < target) {
                        l++;
                    } else if(arr[l] + arr[r] > target) {
                        r--;
                    }
                    else {
                        vector<int> v = {arr[i], arr[j], arr[l], arr[r]};
                        ans.push_back(v);
                        
                        while(l < r and arr[l] == v[2]) l++;
                        while(l < r and arr[r] == v[3]) r--;
                    }
                }
                
                j++;
                while(j<n and arr[j] == arr[j-1]) j++;
            }
            
            i++;
            while(i<n and arr[i] == arr[i-1]) i++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends