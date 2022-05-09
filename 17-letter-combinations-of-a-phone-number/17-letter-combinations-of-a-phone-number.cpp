class Solution {
public:
    map<char, string> alpha;
    // vector<string> ans;
    Solution() {
        // ans = {};
        alpha['2'] = "abc";        
        alpha['3'] = "def";
        alpha['4'] = "ghi";
        alpha['5'] = "jkl";
        alpha['6'] = "mno";
        alpha['7'] = "pqrs";
        alpha['8'] = "tuv";
        alpha['9'] = "wxyz";

    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        for(int i=digits.size()-1; i>=0; i--) {
            vector<string> temp = ans;
            ans.clear();
            string str = alpha[digits[i]];
            for(int i=0; i<str.size(); i++) {
                if(temp.size() == 0) {
                    string s(1, str[i]);
                    ans.push_back(s);
                }
                else {
                    for(int j=0; j<temp.size(); j++) {
                        ans.push_back(str[i] + temp[j]);
                    }
                }
            }
        }
        return ans;
    }
};