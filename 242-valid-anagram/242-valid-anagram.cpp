class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26, 0);
        for(char ch : s) {
            v[ch - 'a']++;
        }
        for(char ch: t) {
            v[ch - 'a']--;
        }
        for(int i: v) {
            if(i != 0) return false;
        }
        return true;
    }
};