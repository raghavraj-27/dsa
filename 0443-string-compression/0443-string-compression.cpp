class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, j = 0, n = chars.size();
        
        string ans = "";
        while(j < chars.size()) {
            while(j < n and chars[i] == chars[j]) {
                j++;
            }
            
            if(j-i == 1) {
                ans = ans + chars[i];
            } else {
                ans = ans + chars[i] + to_string(j-i);
            }
            
            i = j;
        }
        
        for(int i=0; i<ans.size(); i++) {
            chars[i] = ans[i];
        }
        
        return ans.size();
    }
};