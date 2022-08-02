class Solution {
public:
    vector<int> createLPS(string s) {
        int i=1, j=0; 
        vector<int> res(s.size());
        
        while(i < s.size()) {
            if(s[i] == s[j]) {
                res[i] = j+1;
                i++; j++;
            } else if(j > 0) {
                j = res[j-1];
            } else {
                res[i] = 0;
                i++;
            }
        }
        
        return res;
    }
    
    bool check(string s, string t) 
    {
        vector<int> lps = createLPS(t);
        
        int i=0, j=0;
        while(i < s.size() and j < t.size()) {
            if(s[i] == t[j]) {
                i++; j++;
            } else if(j > 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
        
        if(j == t.size()) return true;
        
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
        string temp = a; 
        int cnt = 1;
        
        while(a.size() < b.size()) {
            a += temp;
            cnt++;
        }
        
        if(check(a, b))
            return cnt; 
        
        if(check(a+temp, b))
            return ++cnt;
        
        return -1;
    }
};