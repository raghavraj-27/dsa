class Solution {
public:
    string reverseWords(string s) {
        int i=0, n=s.size(); 
        
        string temp="", ans = ""; 
        
        while(i < n) 
        {
            char ch = s[i]; 
            
            if(ch != ' ') {
                temp += ch; 
            } else if(ch == ' ') {
                if(ans == "") {
                    ans = temp; 
                } else if(temp != "" and ans != "") {
                    ans = temp + " " + ans;
                }
                temp = "";
            }
            i++;
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