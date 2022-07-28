class Solution {
public:
    vector<int> createLPS(string needle) {
        int i=1, j=0;
        vector<int> res(needle.size()); 
        
        while(i<needle.size()) {
            if(needle[i] == needle[j]) {
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
    
    int strStr(string haystack, string needle) {
        vector<int> lps = createLPS(needle); 
        int i=0, j=0; 
        
        while(i<haystack.size() and j<needle.size())
        {
            if(haystack[i] == needle[j]) {
                i++; j++;
            } else if(j>0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
        
        if(j==needle.size()) {
            return i-j;
        }
        
        return -1;
    }
};