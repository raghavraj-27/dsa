class Solution {
public:
    bool same(map<char, int>& f1, map<char, int>& f2) {
        int cnt1 = 0, cnt2 = 0;
        for(char ch='a'; ch<='z'; ch++) {
            if(f1[ch] > 0) cnt1++;
            if(f2[ch] > 0) cnt2++;
        }
        return cnt1 == cnt2;
    }
    bool isItPossible(string word1, string word2) {
        map<char, int> f1, f2;
        for(char ch: word1) f1[ch]++;
        for(char ch: word2) f2[ch]++;
        
        for(char i='a'; i<='z'; i++) {
            for(char j='a'; j<='z'; j++) {
                // if(i == j) continue;
                if(not(f1[i] > 0 and f2[j] > 0)) continue;
                
                f1[i]--;
                f1[j]++;
                
                f2[j]--;
                f2[i]++;
                
                if(same(f1, f2)) {
                    return true;
                }
                
                f1[i]++;
                f1[j]--;
                f2[j]++;
                f2[i]--;
            }
        }
        
        return false;
    }
};