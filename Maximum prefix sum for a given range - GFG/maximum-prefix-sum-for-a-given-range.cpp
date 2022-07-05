// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class SGTree {
    vector<int> seg;
    public:
    SGTree(int n) {
        seg.resize(n);
    }
    
    int getMax(int a, int b, int c) {
        return max(a, max(b, c));
    }
    
    void build(int ind, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        
        int mid = (low + high) / 2;
        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid+1, high, arr);
        seg[ind] = max(seg[2*ind + 1], seg[2*ind + 2]);
        // seg[ind] = getMax(seg[2*ind + 1], seg[2*ind + 2], seg[2*ind + 1] + seg[2*ind + 2]);
    }
    
    int query(int ind, int low, int high, vector<int>& arr, int l, int r) {
        // no overlap, l..r..low..high, low..high..l..r
        if(r < low or high < l) return INT_MIN;
        
        // l..low..high..r
        if(l <= low and high <= r) return seg[ind];
        
        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2*ind + 1, low, mid, arr, l, r);
        int right = query(2*ind + 2, mid+1, high, arr, l, r);
        
        // return getMax(left, right, left + right);
        return max(left, right);
    }
};

class Solution{
  public:
    vector<int> maxPrefixes(int a[], int L[], int R[], int N, int Q) {
        SGTree sg(4*N);
        vector<int> prefix(a, a+N);
        for(int i=1; i<N; i++) {
            prefix[i] += prefix[i-1];
        }
        
        // for(int i=0; i)
        sg.build(0, 0, N-1, prefix);
        
        vector<int> ans;
        for(int i=0; i<Q; i++) {
            int l = L[i], r = R[i];
            int max_sum = sg.query(0, 0, N-1, prefix, l, r);
            if(l > 0) {
                max_sum = max_sum - prefix[l-1];
            }
            ans.push_back(max_sum);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[n], L[q], R[q];
        
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < q; i++) cin >> L[i] >> R[i];
        Solution obj;
        vector<int> ans = obj.maxPrefixes(a, L, R, n, q);
        for (auto it : ans) 
            cout << it << " ";
        cout << endl;
    }
}
  // } Driver Code Ends