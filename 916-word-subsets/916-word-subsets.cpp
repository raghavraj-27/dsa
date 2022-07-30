class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        set<string> st(words2.begin(), words2.end());
        vector<string> b(st.begin(), st.end());
        
        vector<int> v(26, 0);
        for(string str: b) {
            vector<int> temp(26, 0);
            for(int i=0; i<str.size(); i++) {
                int ch = str[i] - 'a';
                temp[ch]++;
                v[ch] = max(v[ch], temp[ch]);
            }
        }
        
        vector<string> ans;
        
        for(string a: words1) {
            vector<int> v1(26, 0);
            for(int i=0; i<a.size(); i++) {
                v1[a[i] - 'a']++;
            }
            
            bool flag = true;
            for(int i=0; i<26; i++) {
                if(v1[i] >= v[i]) {
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                ans.push_back(a);
            }
        }
        
        return ans;
    }
};