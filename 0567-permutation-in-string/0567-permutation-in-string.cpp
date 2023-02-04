class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26), mp2(26);
        int n = s1.size();
        
        for(char ch: s1) {
            mp1[ch-'a']++;
        }
        
        for(int i=0; i<s2.size(); i++) {
            if(i < n) mp2[s2[i] - 'a']++;
            // if(i == s2.size()-1 and mp1 == mp2) return true
            if(mp1 == mp2) return true;

            if(i >= n) {
                mp2[s2[i-n] - 'a']--;
                mp2[s2[i] - 'a']++;
            }
        }
        
        return mp1 == mp2;
    }
};