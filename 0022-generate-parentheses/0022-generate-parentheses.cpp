class Solution {
public:
    vector<string> ans;
    unordered_set<string> store;
    bool check(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            
            if(s[i] == ')') {
                if(st.top() == '(') {
                    st.pop();
                } else {
                    break;
                }
            } else {
                st.push('(');
            }
        }
        
        return st.empty();
    }
    void reverse(int i, char ch, string & s) {
        if(ch == ')') s[i] = '(';
        if(ch == '(') s[i] = ')';
    }
    void f(string s, int ind, int n) {
        if(check(s)) {
            if(store.find(s) == store.end()) {
                store.insert(s);
                ans.push_back(s);
            }
        }
        
        if(ind == n) return;
        
        reverse(ind, s[ind], s);
        f(s, ind+1, n);
        reverse(ind, s[ind], s);
        f(s, ind+1, n);
    } 
    vector<string> generateParenthesis(int n) {
        string s = "";
        for(int i=0; i<n; i++) s = s + "(";        
        for(int i=0; i<n; i++) s = s + ")";
        
        ans.clear();
        store.clear();
        // ans.push_back(s);
        f(s, 1, n+n);
        return ans;
    }
};
