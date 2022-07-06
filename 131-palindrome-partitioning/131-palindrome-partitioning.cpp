class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left <= right) {
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    void solve(int ind, string& s, vector<string>& strs) {
        if(ind >= s.size()) {
            ans.push_back(strs);
            return;
        }
        
        for(int i=ind; i<s.size(); i++) {
            string str = s.substr(ind, i-ind+1);
            if(isPalindrome(str)) {
                strs.push_back(str);
                solve(i + 1, s, strs);
                strs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> strs;
        solve(0, s, strs);
        return ans;
    }
};