// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> stored;
        for(int i=0; i<N; i++) {
            stored.insert(arr[i]);
        }
        
        int longestStreak = 0;
        
        for(int i=0; i<N; i++) {
            if(stored.find(arr[i]-1) != stored.end()) {
                continue;
            }
            
            int num = arr[i];
            int currStreak = 0;
            while(stored.find(num) != stored.end()) {
                num++;
                currStreak++;
            }
            
            longestStreak = max(longestStreak, currStreak);
        }
        
        return longestStreak;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends