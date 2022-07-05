// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class SGTree {
    vector<int> seg;
public:
    SGTree(int n) {
        seg.resize(n);
    }
    
    void build(int ind, int low, int high, int arr[]) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        
        int mid = (low + high) / 2;
        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid+1, high, arr);
        seg[ind] = seg[2*ind + 1] ^ seg[2*ind + 2];
    }
    
    int query(int ind, int low, int high, int l, int r) {
        // no overlar, l..r..low..high, low..high..l..r
        if(r < low or high < l) return 0;
        
        // complete overlap, l..low..high..r
        if(l <= low and high <= r) return seg[ind];
        
        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2*ind + 1, low, mid, l, r);
        int right = query(2*ind + 2, mid+1, high, l, r);
        return left ^ right;
    }
};

class Solution{
public:
    vector<int> specialXor(int N, int Q, int a[], vector<int> quer[])
    {
        int nxor = 0;
        for(int i=0; i<N; i++) nxor = nxor ^ a[i];
        
        SGTree sg(4*N + 1);
        sg.build(0, 0, N-1, a);
        
        vector<int> ans;
        // for(auto q : quer) {
        //     int l = q[0]-1, r = q[1]-1;
        //     int xor_l_r = sg.query(0, 0, N-1, l, r);
        //     ans.push_back(nxor ^ xor_l_r);
        // }
        for(int i=0; i<Q; i++) {
            int l = quer[i][0], r = quer[i][1];
            // cout<<l<<" - "<<r<<endl;
            int xor_l_r = sg.query(0, 0, N-1, l-1, r-1);
            ans.push_back(nxor ^ xor_l_r);
        }
        
        return ans;
    }
}; 

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int a[N];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        int l, r;
        vector<int> query[Q];
        for(int i = 0;i < Q;i++){
            cin>>l>>r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
        
        Solution ob;
        vector<int> ans = ob.specialXor(N, Q, a, query);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}  // } Driver Code Ends