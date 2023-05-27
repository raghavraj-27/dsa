class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        unordered_set<char> st;
        
        for(int i=0; i<s.size(); i++) {
            if(st.find(s[i]) != st.end()) {
                ans++;
                st.clear();
            }
            st.insert(s[i]);
        }
        
        if(st.size()) ans++;
        return ans;
    }
};