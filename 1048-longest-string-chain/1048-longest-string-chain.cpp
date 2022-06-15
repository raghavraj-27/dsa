bool cmp(string s1, string s2) {
    return s1.size() < s2.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        
        int ans = 1;
        sort(words.begin(), words.end(), cmp);
        for(int i=0; i<words.size(); i++) 
        {
            string str = words[i];
            dp[str] = 1;
            for(int p=0; p<str.size(); p++) 
            {
                string word = str.substr(0,p) + str.substr(p+1);
                if(dp.find(word) != dp.end()) 
                {
                    dp[str] = dp[word] + 1;
                    ans = max(ans, dp[str]);
                }
                // if(st.find(word) != st.end()) {
                //     ans++;
                //     break;
                // }
            }
        }
        return ans;
    }
};