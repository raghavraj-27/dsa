class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for(int i=0; i<n; i++) {
            ans += 'a';
        }
        
        k = k - n;
        for(int i=n-1; i>=0; i--) {
            if(k==0) return ans;
            else if(k < 25) {
                ans[i] = (char)('a' + k);
                k = 0;
            }
            else {
                ans[i] = 'z';
                k = k - 25;
            }
        }
        return ans;
    }
};