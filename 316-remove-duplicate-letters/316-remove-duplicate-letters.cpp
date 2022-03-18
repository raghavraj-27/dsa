class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> freq;
        for(char ch : s) {
            freq[ch]++;
        }
        
        vector<bool> exist(26, false);
        stack<char> st;
        
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            freq[ch]--;
            if(exist[ch - 'a'] == true) continue;
            
            exist[ch - 'a'] = true;
            while(not st.empty() and st.top() > ch and freq[st.top()] > 0) {
                exist[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(ch);
        }
        
        string ans = "";
        while(st.empty() != true) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};