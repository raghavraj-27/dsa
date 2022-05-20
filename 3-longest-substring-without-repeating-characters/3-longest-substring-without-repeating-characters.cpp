class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> store; 
        int length=0, n = s.size(), max_len = INT_MIN;
        int ptr=0;
        
        for(int i=0; i<n; i++) {
            if(store.find(s.at(i)) == store.end()) {
                // length++; 
                store.insert(s.at(i));
            } else {
                // max_len = max(length, max_len);
                while(store.find(s.at(i)) != store.end() and ptr<i) {
                    char ch = s.at(ptr);
                    store.erase(store.find(ch));
                    ptr++;
                    // length--;
                }
                
                store.insert(s.at(i));
                // length++;
            }
            max_len = max(max_len, i - ptr + 1);
        }
        
        return max(length, max_len);
    }
};