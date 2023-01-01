class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, vector<int>> mp;
        // set<char> pt;
        for(int i=0; i<pattern.size(); i++) {
            
            mp[pattern[i]].push_back(i);
        }
        
        map<string, vector<int>> sp;
        set<string> st;
        // map<string, vector<
        vector<string> str;
        stringstream ss(s);
        string word;
        int i = 0;
        while(ss >> word) {
            sp[word].push_back(i);
            // cout<<word;
            st.insert(word);
            str.push_back(word);
            i++;
        }
        if(pattern.size() != str.size()) return false;
        if((int)mp.size() != (int)st.size()) return false;
        
        for(auto p: mp) {
            vector<int> v = p.second;
            set<string> temp;
            for(int i=0; i<v.size(); i++) {
                // cout<<v[i]<<" ";
                temp.insert(str[v[i]]);
            }
            // cout<<endl;
            if(temp.size() > 1) return false;
        }
        
        return true;
    }
};