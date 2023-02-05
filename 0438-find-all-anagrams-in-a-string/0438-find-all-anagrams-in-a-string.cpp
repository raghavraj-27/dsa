class Solution {
public:
    bool checkEqual(vector<int>& v1, vector<int>& v2) {
        for(int i=0; i<26; i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        
        vector<int> ans;
        vector<int> freq_p(26, 0), freq_s(26, 0);
        int n = p.size();
        
        for(char ch: p) {
            freq_p[ch - 'a']++;
        }
        
        int i = 0;
        while(i < s.size()) {
            if(i < n) freq_s[s[i] - 'a']++;
            
            if(i == n-1 and checkEqual(freq_s, freq_p)) ans.push_back(0);
            if(i >= n) {
                freq_s[s[i-n] - 'a']--;
                freq_s[s[i] - 'a']++;
                if(checkEqual(freq_s, freq_p)) ans.push_back(i-n+1);
            }
            i++;
        }
        
        return ans;
    }
};