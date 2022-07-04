// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int left = 0, right = 0, n = s.size();
    int maxlen = 0;
    set<char> st;
    while(right < n) {
        char ch = s[right];
        
        if(st.find(ch) != st.end()) {
            while(left < right and st.find(ch) != st.end()) {
                st.erase(s[left]);
                left++;
            }
        }
        
        st.insert(s[right]);
        
        maxlen = max(maxlen, right - left + 1);
        right++;
    }
    
    return maxlen;
}