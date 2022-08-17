class Solution {
public:
    map<char, string> mp;
    
    Solution() {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int i=0;
        for(char ch='a'; ch<='z'; ch++, i++) {
            mp[ch] = v[i];
        }
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        for(string str: words) {
            string s = "";
            for(char ch: str) {
                s = s + mp[ch];
            }
            st.insert(s);
        }
        
        return st.size();
    }
};