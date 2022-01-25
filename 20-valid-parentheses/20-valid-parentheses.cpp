class Solution {
public:
    bool isValid(string exp) {
        stack<char> st;
        int i=0;
        while(i < exp.size()) 
        {
            char ch = exp[i];
            if(ch=='(' or ch=='{' or ch=='[') {
                st.push(ch);
            } else {
                if(not st.empty()) {
                char prev = st.top();

                    if(ch==')' and prev=='(') st.pop();
                    else if(ch=='}' and prev=='{') st.pop();
                    else if(ch==']' and prev=='[') st.pop();
                    else return false;
                }
                else return false;
            }
            i++;
        }

        return st.empty();
    }
};