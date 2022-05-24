class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; 
        stack<char> ct;
        st.push(-1);
        
        int max_len = 0;
        
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            
            if(ch == '(') {
                st.push(i);
                ct.push(ch);
            } else {
                if(not ct.empty() and ct.top() == '(') {
                    ct.pop(); 
                    st.pop();
                    max_len = max(max_len, i - st.top());
                    // st.push(i);
                } else {
                    st.push(i);
                    // ct.push(ch);
                }
            }
        }
        
        return max_len;
    }
};