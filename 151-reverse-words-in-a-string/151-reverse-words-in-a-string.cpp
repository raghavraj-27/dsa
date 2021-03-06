class Solution {
public:
    string reverseWords(string s) {
        int i=0, n=s.size(); 
        
        string temp="", ans = ""; 
        
        for(int i=0; i < n; i++) 
        {
            char ch = s[i]; 
            
            if(ch != ' ') {
                temp += ch; 
            } else if(ch == ' ' and temp == "") {
                // i++;
                continue;
            }
            else if(ch == ' ') {
                ans = temp + ' ' + ans;
                temp = "";
            }
            // i++;
        }
        
        if(temp != "") {
            ans = temp + " " + ans;
        }
        
        while(ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};