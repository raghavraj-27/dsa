class Solution {
public:
    bool checkPalindrome(string str) {
        int l = 0, h = str.size()-1;
        while(l < h) {
            if(str[l++] != str[h--]) return false;
        }
        return true;
    }
    string ithBase(int num, int base) {
        string ans = "";
        while(num > 0) {
            int rem = num % base;
            ans = ans + to_string(rem);
            num /= base;
        }
        // cout<<ans<<endl;
        return ans;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2; i<=n-2; i++) {
            if(not checkPalindrome(ithBase(n, i))) {
                return false;
            }
        }
        return true;
    }
};