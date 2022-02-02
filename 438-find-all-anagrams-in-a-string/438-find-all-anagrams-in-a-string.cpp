class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pvec(26), svec(26);
        for(char ch : p) {
            pvec[ch-'a']++;
        }
        
        vector<int> ans;
        int pn = p.size(), sn = s.size();
        for(int i=0; i<sn; i++) {
            if(i < pn) {
                svec[s[i] - 'a']++;
                if(i == pn-1) {
                    if(svec == pvec)
                        ans.push_back(0);
                }
            }
            
            if(i>=pn) {
                svec[s[i-pn] - 'a']--;
                svec[s[i] - 'a']++;
                if(svec == pvec) {
                    ans.push_back(i-pn+1);
                }
            }
        }
        
        return ans;
    }
};