class Solution {
public:
    bool isASubSeqOfB(string a, string b) {
        if(a.size() > b.size()) return false;
        int i=0;
        for(char ch : b) {
            if(i < a.size() and a[i] == ch) i++;
        }
        if(i == a.size()) return true;
        return false;
    }
    
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        
        for(int i=0; i<strs.size(); i++) {
            string A = strs[i]; 
            int j;
            for(j=0; j<strs.size(); j++) {
                if(i == j) continue;
                string B = strs[j];
                if(isASubSeqOfB(A, B)) break; 
            }
            
            if(j == strs.size()) res = max(res, static_cast<int>(A.size()));
        }
        
        return res;
    }
};