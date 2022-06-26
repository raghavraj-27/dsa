// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

class element {
    public:
    int value, row, col;
    element(int val, int r, int c) {
        value = val;
        row = r;
        col = c;
    }
};

struct compare
{
    bool operator()(element a,element b)
    {
        return a.value > b.value;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // min heap
        priority_queue<element, vector<element>, compare> pq;
        
        for(int i=0; i<K; i++) {
            element ele(arr[i][0], i, 0);
            pq.push(ele);
        }
        
        vector<int> ans;
        
        while(not pq.empty()) {
            element e = pq.top();
            pq.pop();
            
            ans.push_back(e.value);
            int i = e.row, j = e.col;
            
            if(j < K-1) {
                element ele(arr[i][j+1], i, j+1);
                pq.push(ele);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends