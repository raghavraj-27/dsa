// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends

// class SGTree {
//     vector<int> seg;
//     public:
//     SGTree(int n) {
//         seg.resize(n);
//     }
    
//     int getRoot() {
//         return seg[0];
//     }
int seg[100000];
    void build(int ind, int low, int high, int arr[]) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        
        int mid = (low + high) / 2;
        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid+1, high, arr);
        seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
    }
    
    int query(int ind, int low, int high, int l, int r) {
        // no overlap, l..r..low..high, low.high..l..r
        if(r < low or high < l) return INT_MAX;
        
        // complete overlap, l..low..high..r
        if(l <= low and high <= r) return seg[ind];
        
        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2*ind + 1, low, mid, l, r);
        int right = query(2*ind + 2, mid+1, high, l, r);
        return min(left, right);
    }
// };
/* The functions which 
builds the segment tree */
// SGTree sg(4001);
int *constructST(int arr[],int n)
{
    // int seg[4*n+1];
    build(0, 0, n-1, arr);
    return seg;
}

int RMQ(int st[] , int n, int a, int b)
{
    return query(0, 0, n-1, a, b);
}


