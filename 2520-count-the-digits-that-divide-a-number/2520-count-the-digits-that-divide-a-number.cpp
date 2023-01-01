class Solution {
public:
    int countDigits(int num) {
        map<int, int> freq;
        string s = to_string(num);
        
        for(int i=0; i<s.size(); i++) {
            freq[s[i] - '0']++;
        }
        int ans = 0;
        for(auto p: freq) {
            if(num % p.first == 0) {
                ans += p.second;
            }
        }
        
        return ans;
    }
};