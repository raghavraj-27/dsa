// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    vector<int> ans; 
    sort(a, a+n);
    int same = 0;
    for(int i=0; i<n-1; i++) {
        if(a[i] == a[i+1]) {
            same++;
        }
    }
    if(same == n-1 and n!=1) {
        ans.push_back(-1); return ans;
    }
    
    for(int i=0, j=n-1; i <=j; i++, j--) {
        if(i!=j)
        ans.push_back(a[j]);
        ans.push_back(a[i]);
    }
    
    return ans;
}

// N is 1 based indexing
// elevator starts freom ground, move up X floors and down Y floors
// code is there
