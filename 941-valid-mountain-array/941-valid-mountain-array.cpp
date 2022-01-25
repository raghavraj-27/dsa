class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int i = 0, n = arr.size();
        while(i<n-1 and arr[i] < arr[i+1]) {
            i++;
        }
        if(i==n-1) return false;
        
        int j=arr.size()-1;
        while(j>=1 and arr[j-1] > arr[j]) {
            j--;
        }
        if(j==0) return false;
        
        return i==j;
    }
};
