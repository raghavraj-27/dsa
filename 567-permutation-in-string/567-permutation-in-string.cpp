class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(); 
        vector<int> mp1(26, 0), mp2(26, 0);
        
        for(auto ch : s1) {
            mp1[ch-'a']++;
        }
        
        for(int i=0; i<s2.size(); i++) {
            if(i < n) {
                mp2[s2[i] - 'a']++;
                if(i==n-1 and mp2==mp1)
                    return true;
            }
            
            if(i >= n) {
                mp2[s2[i-n] - 'a']--;
                mp2[s2[i] - 'a']++;
                if(mp1 == mp2)
                    return true;
            }
        }
        
        return false;
    }
};