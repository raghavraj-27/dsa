class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        int ans = 0;
        
        for(auto str : words) {
            string rts = str; 
            reverse(rts.begin(), rts.end());
            
            if(mp[rts] > 0) {
                ans += 4;
                mp[rts]--;
            }
            else {
                mp[str]++;
            }
        }
        
        for(int i=0; i<words.size(); i++) {
            string s = words[i];
            int cnt = mp[s]; 
            if(s[0] == s[1] and cnt > 0) {
                ans += 2;
                break;
            }
        }
        
        return ans;
    }
};