class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        
        string str = "";
        for(int i=0; i<s.size(); i++) {
            if(str.size() < k) {
                str = str + s[i];
            } else {
                st.insert(str);
                str.erase(str.begin());
                str = str + s[i];
            }
        }
        st.insert(str);
        
        long totalSubstringWIthK = pow(2, k);
        return (st.size() == totalSubstringWIthK);
    }
};