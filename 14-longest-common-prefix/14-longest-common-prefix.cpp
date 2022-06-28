class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort(strs.begin(), strs.end()); 
        
        string str = strs[0]; 
        string ans = ""; 
        for(int i=0; i<str.size(); i++) {
            char ch = str[i];
            bool flag = true;
            
            for(int j=1; j<strs.size(); j++) {
                if(ch != strs[j][i]) {
                    flag = false; 
                    break;
                }
            }
            
            if(flag == true) {
                ans += ch; 
            } else {
                break;
            }
        }
        
        return ans;
    }
};