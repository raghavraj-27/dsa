class Solution {
public:
    void calc(int p, vector<int>& c, vector<int>& v, int k, int& ans) {
        if(p >= c.size()) {
            int maxm = INT_MIN;
            for(int i=0; i<k; i++) {
                maxm = max(v[i], maxm);
            }
            ans = min(ans, maxm);
            return;
        }
        
        for(int i=0; i<k; i++) {
            v[i] += c[p];
            calc(p+1, c, v, k, ans);
            v[i] -= c[p];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k, 0);
        int ans = INT_MAX;
        calc(0, cookies, v, k, ans);
        
        return ans;
    }
};