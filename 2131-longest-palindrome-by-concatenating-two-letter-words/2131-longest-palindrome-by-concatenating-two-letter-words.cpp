class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_multiset<string> s;
        int ans = 0;
        
        for(auto str : words) {
            string rts = str; 
            reverse(rts.begin(), rts.end());
            
            if(s.find(rts) == s.end())
                s.insert(str);
            else {
                ans += 4;
                cout<<str<<" ";
                s.erase(s.find(rts)); 
            }
        }
        
        for(auto it : s) {
            if(it[0] == it[1]) {
                ans += 2;
                return ans;
            } 
            // else if(it[0] == it[1]) {
                // ans += 2;
            // }
        }
        
        return ans;
    }
};