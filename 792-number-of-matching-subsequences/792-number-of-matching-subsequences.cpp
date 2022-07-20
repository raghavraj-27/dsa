class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& word) {
        map<char, vector<int>> mp;
        map<string, int> freq;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        
        int ans = 0;
        set<string> st(word.begin(), word.end());
        for(string str : word) {
            freq[str]++;
        }
        vector<string> words(st.begin(), st.end());
        
        for(int i=0; i<words.size(); i++) {
            
            string str = words[i]; 
            int prev = -1;
            bool flag = true;
            for(int j=0; j<str.size(); j++) {
                char ch = str[j]; 
                vector<int> v = mp[ch];
                
                int ind = upper_bound(v.begin(), v.end(), prev) - v.begin();
                if(ind == v.size()) {
                    flag = false;
                    break;
                }
                if(ind < v.size() and v[ind] < prev) {
                    flag = false;
                    break;
                }
                prev = v[ind];
            }
            // cout<<str<<" ";
            if(flag) {
                ans += freq[str];
            }
        }
        
        return ans;
    }
};