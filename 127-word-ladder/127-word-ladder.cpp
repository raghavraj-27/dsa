class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        unordered_set<string> dict;
        for(auto word : wordList) {
            dict.insert(word);
        }
        
        if(dict.find(end) == dict.end()) return 0;
        
        queue<string> q;
        q.push(start);
        int len = 0;
        while(not q.empty()) {
            len++;
            int sz = q.size(); 
            for(int i=0; i<sz; i++) {
                string str = q.front();
                q.pop(); 
                for(int i=0; i<str.size(); i++) {
                    char temp = str[i];
                    for(char ch='a'; ch<='z'; ch++) {
                        str[i] = ch;
                        if(str == end) return len+1;
                        if(dict.find(str) == dict.end()) continue;
                        
                        dict.erase(str);
                        q.push(str);
                    }
                    str[i] = temp;
                }
            }
        }
        return 0;
    }
};