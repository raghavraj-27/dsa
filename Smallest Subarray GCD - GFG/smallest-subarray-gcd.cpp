// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
// map<int, vector<int>> mp;
// class SGTree {
// 	vector<int> seg;
// public:
// 	SGTree(int n) {
// 		seg.resize(4*n + 1);
// 	}

// 	void build(int ind, int low, int high, int arr[]) {
// 		if(low == high) {
// 			seg[ind] = arr[low];
// // 			mp[seg[ind]].push_back(1);
// 			return;
// 		}

// 		int mid = low + (high - low) / 2;
// 		build(2*ind + 1, low, mid, arr);
// 		build(2*ind + 2, mid+1, high, arr);
		
//         seg[ind] = __gcd(seg[2*ind + 1], seg[2*ind + 2]);
//         // mp[seg[ind]].push_back(high - low + 1);
// 	}
	
// 	int query(int ind, int low, int high, int l, int r) {
// 	    // nor overlap, l..r..low..high, low..high..l..r
// 	    if(r < low or high < l) return 0;
// 	    // complete overlap, l..low..high..r
// 	    if(l<=low and high <= r) return seg[ind];
	    
// 	    int mid = (low + high) / 2;
// 	    int left = query(2*ind + 1, low, mid, l, r);
// 	    int right = query(2*ind + 2, mid+1, high, l, r);
// 	    return __gcd(left, right);
// 	}
// };

// class Solution{   
// public:
//     int findSmallestSubArr(int arr[], int n, int g) {
//         SGTree sg(4*n + 1);
//         // mp.clear();
//         sg.build(0, 0, n-1, arr);
        
//         bool possible = false;
//         for(int i=0; i<n; i++) {
//             if(g == arr[i]) return 1;
//             if(arr[i] % g == 0) {
//                 possible = true;
//             }
//         }
        
//         if(possible == false) return -1;
        
//         int ans = INT_MAX;
//         int closest = 0;
        
//         for(int i=0; i<n-1; i++) {
//             // int l=2,r=n-i;
//             int l = i, r = n-1;
//             while(l<=r){
//                 int m = (l+r)>>1;
//                 int gc = sg.query(0, 0, n-1, i,m);
//                 if(gc<=g){
//                     ans= gc==g ? min(ans,m):ans;
//                     r=m-1;
//                 }else
//                     l=m+1;
//             }
//         }
        
//         if(ans == INT_MAX) return -1;
        
//         return ans;
//     }
// };

class Solution{
    int * st;
    int ans;
    public:
    
    int gcd(int a,int b=0){
        return b ? gcd(b,a%b) : a;
    }
        
    void build(int arr[],int n){
        for(int i=0;i<n;i++)
            st[n+i] = arr[i];
        for(int i=n-1;i>0;i--)
            st[i]=gcd(st[i<<1],st[i<<1 | 1]);
    }
    int query(int l,int r,int n){
        int gc=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)
                gc=gcd(st[l++],gc);
            if(r&1)
                gc=gcd(st[--r],gc);
        }
        return gc;
    }
    int findSmallestSubArr(int arr[], int n, int g) {
        for(int i=0;i<n;i++)
                if(arr[i]==g)
                    return 1;
        st= new int[2*n],ans=INT_MAX;
        build(arr,n);
        for(int i=0;i<n-1;i++){
            int l=2,r=n-i;
            while(l<=r){
                int m = (l+r)>>1;
                int gc = query(i,i+m,n);
                if(gc<=g){
                    ans= gc==g ? min(ans,m):ans;
                    r=m-1;
                }else
                    l=m+1;
            }
        }
        return ans==INT_MAX ? -1:ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, g;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> g;
        Solution ob;
        auto ans = ob.findSmallestSubArr(arr, n, g);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends