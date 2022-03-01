class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        while(n != 0) {
            int m = n;
            int cnt = 0;
            while(m != 0) {
                if(m%2 != 0) cnt++;
                m = m / 2;
            }
            ans[n] = cnt;
            n--;
        }
        
        return ans;
    }
};