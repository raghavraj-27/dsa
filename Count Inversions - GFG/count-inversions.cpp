// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    long long int ans;
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long low, long long mid, long long high, long long arr[], long long temp[]) {
        long long i = low, j=mid, k = low;
        while(i <= mid-1 and j<=high) {
            if(arr[i] > arr[j]) {
                ans += mid-i;
                temp[k] = arr[j];
                j++; k++;
            } else {
                temp[k] = arr[i];
                i++; k++;
            }
        }
        
        while(i <= mid-1) {
            temp[k++] = arr[i++];
        }
        
        while(j <= high) {
            temp[k++] = arr[j++];
        }
        
        for(i=low; i<=high; i++) {
            arr[i] = temp[i];
        }
    }
    
    void mergeSort(long long low, long long high, long long arr[], long long temp[]) {
        if(high <= low) return;
        
        long long mid = (low + high) >> 1;
        mergeSort(low, mid, arr, temp);
        mergeSort(mid+1, high, arr, temp);
        
        merge(low, mid+1, high, arr, temp);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        ans = 0LL;
        long long temp[N];
        mergeSort(0, N-1, arr, temp);
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends