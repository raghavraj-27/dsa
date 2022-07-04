// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        map<int, int> mp;
        int max_len = 0, sum = 0;
        
        for(int i=0; i<n; i++) {
            sum += a[i];
            
            if(mp.find(sum) != mp.end()) {
                max_len = max(max_len, i-mp[sum]);
            } else {
                mp[sum] = i;
            }
            
            if(sum == 0) {
                max_len = max(max_len, i+1);
            }
        }
        
        return max_len;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends