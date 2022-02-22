class Solution {
public:
    unordered_map<char, int> mp;
    
    Solution() {
        int i = 1;
        for(char ch = 'A'; ch<='Z'; ch++, i++) {
            mp[ch] = i;
        }
    }
    
    int titleToNumber(string A) {
        int ans = 0;
        int n = A.size();
        for(int i=0; i<A.size()-1; i++) {
            ans += pow(26, (n - i - 1)) * mp[A[i]];
        }
        ans += mp[A[n - 1]];
        
        return ans;
    }
};