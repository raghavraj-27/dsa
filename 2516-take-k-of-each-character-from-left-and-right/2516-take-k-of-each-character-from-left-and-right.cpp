class Solution {
public:
    int takeCharacters(string s, int k) {
        map<char, int> freq;
        for(char ch: s) freq[ch]++;
        
        if(not (freq['a'] >= k and freq['b'] >= k and freq['c'] >= k)) return -1;
        
        int n = s.size();
        int i = n-1, j = n-1;
        int ans = n;
        
        while(i >= 0) {
            freq[s[i]]--;
            while(freq['a']<k or freq['b']<k or freq['c']<k) {
                freq[s[j]]++;
                j--;
            }
            
            ans = min(ans, i + n-1-j);
            i--;
        }
        
        return ans;
    }
};