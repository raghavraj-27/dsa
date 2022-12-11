class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, ans = 0;
        unordered_set<char> store;
        
        while(right < s.size()) {
            if(store.find(s[left]) != store.end()) {
                while(left < right and store.find(s[right]) != store.end()) {
                    store.erase(s[left]);
                    left++;
                }
            }
            
            store.insert(s[right]);
            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
};