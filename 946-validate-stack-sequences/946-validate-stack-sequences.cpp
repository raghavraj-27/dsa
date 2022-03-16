class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        vector<int> mypop;
        for(int i=0; i<pushed.size(); i++) {
            st.push(pushed[i]);
            while(not st.empty() and st.top() == popped[j]) {
                mypop.push_back(popped[j]);
                j++;
                st.pop();
            }
        }
        
        return mypop == popped;
    }
};