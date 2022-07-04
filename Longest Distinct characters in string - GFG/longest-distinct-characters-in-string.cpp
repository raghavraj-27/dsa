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
    map<char, int> freq;
    int maxlen = 0, left = 0, right = 0;
    
    while(right < s.size()) {
        if(freq.find(s[right]) != freq.end()) {
            left = max(left, freq[s[right]] + 1);
        }
        freq[s[right]] = right;
        
        maxlen = max(maxlen, right - left + 1);
        right++;
    }
    
    return maxlen;
}