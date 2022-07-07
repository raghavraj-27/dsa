// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void solve(int ind, string s, set<string>& ans) {
	    if(ind >= s.size()) {
	        ans.insert(s);
	        return;
	    }
	    
	    for(int i=ind; i<s.size(); i++) {
	        swap(s[i], s[ind]);
	        solve(ind + 1, s, ans);
	        swap(s[i], s[ind]);
	    }
	}
	
	vector<string>find_permutation(string s) {
	   // sort(s.begin(), s.end());
	    set<string> ans;
	    solve(0, s, ans);
	   // sort(ans.begin(), ans.end());
	    vector<string> a(ans.begin(), ans.end());
	    return a;
	}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends