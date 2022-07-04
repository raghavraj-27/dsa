// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    vector<int> findLeftMax(int arr[], int n) {
        vector<int> leftmax(n);
        for(int i=0; i<n; i++) {
            if(i == 0) leftmax[i] = arr[i];
            else leftmax[i] = max(leftmax[i-1], arr[i]);
        }
        return leftmax;
    }
    
    vector<int> findRightMax(int arr[], int n) {
        vector<int> rightmax(n);
        for(int i=n-1; i>=0; i--) {
            if(i == n-1) rightmax[i] = arr[i];
            else rightmax[i] = max(rightmax[i+1], arr[i]);
        }
        return rightmax;
    }
    
    long long trappingWater(int arr[], int n){
        vector<int> leftmax = findLeftMax(arr, n);
        vector<int> rightmax = findRightMax(arr, n);
        
        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans += min(leftmax[i], rightmax[i]) - arr[i];
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends