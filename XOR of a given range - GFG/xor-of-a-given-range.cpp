// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class SGTree {
    vector<int> seg;
    public:
    SGTree(int n) {
        seg.resize(n);
    }
    
    void build(int ind, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        
        int mid = (low + high) >> 1;
        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid+1, high, arr);
        seg[ind] = seg[2*ind + 1] ^ seg[2*ind + 2];
    }
    
    int query(int ind, int low, int high, vector<int>& arr, int l, int r) {
        // no overlap, l..r..low..high or low..high..l..r
        if(r < low or high < l) {
            return 0;
        }
        
        // complete overlap, l..low..high..r
        if(l<=low and high<=r) {
            return seg[ind];
        }
        
        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2*ind + 1, low, mid, arr, l, r);
        int right = query(2*ind + 2, mid+1, high, arr, l, r);
        return left ^ right;
    }
};

class Solution{
    public:
    int getXor(vector<int>&nums, int a, int b){
        SGTree sg(4*nums.size());
        sg.build(0, 0, nums.size()-1, nums);
        
        return sg.query(0, 0, nums.size()-1, nums, a, b);
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        if(a > b)swap(a, b);
        Solution obj;
        int ans = obj.getXor(nums, a, b);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends