class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l = 0, h = s.size();
        
        vector<int> ans;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'I') ans.push_back(l++);
            if(s[i] == 'D') ans.push_back(h--);
        }
        
        if(count(ans.begin(), ans.end(), h) == 0) ans.push_back(h);
        else ans.push_back(l);
        
        return ans;
    }
};