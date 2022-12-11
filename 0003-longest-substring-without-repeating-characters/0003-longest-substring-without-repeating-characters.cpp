class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, ans = 0;
        // unordered_set<char> store;
        map<char, int> mp;
        
        while(right < s.size()) {
            // if(store.find(s[left]) != store.end()) {
            //     while(left < right and store.find(s[right]) != store.end()) {
            //         store.erase(s[left]);
            //         left++;
            //     }
            // }
            if(mp.find(s[right]) != mp.end()) {
                left = max(left, mp[s[right]]+1);
            }
            mp[s[right]] = right;
            // store.insert(s[right]);
            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
};