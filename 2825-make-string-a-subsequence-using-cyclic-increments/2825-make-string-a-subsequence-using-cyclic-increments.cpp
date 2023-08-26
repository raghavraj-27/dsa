class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size(); 
        if(n2 > n1) return false;
        
        int i=0, j=0; 
        
        while(i < n1 and j < n2) {
            if(str1[i] == str2[j]) {
                i++; j++; continue;
            } else {
                if(str1[i]+1 == str2[j]) {
                    j++; i++;
                } else if(str1[i] == 'z' and str2[j] == 'a') {
                    i++; j++;
                } else {
                    i++;
                }
            }
        }
        
        if(j < n2) return false;
        return true;
    }
};