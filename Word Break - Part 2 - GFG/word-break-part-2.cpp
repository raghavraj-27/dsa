// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int ind, string sen, string s, unordered_set<string>& d, vector<string>& ans) {
        if(ind >= s.size()) {
            sen.pop_back();
            ans.push_back(sen);
            return;
        }
        
        for(int i=ind; i<s.size(); i++) {
            string str = s.substr(ind, i-ind+1);
            if(d.find(str) != d.end()) {
                solve(i+1, sen + str + " ", s, d, ans);
            }
        }
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans;
        unordered_set<string> d(dict.begin(), dict.end());
        
        solve(0, "", s, d, ans);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends