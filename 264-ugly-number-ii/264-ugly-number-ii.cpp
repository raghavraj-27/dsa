class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        
        for(int i=2; i<=n; i++) {
            int factor1 = 2 * dp[p2];
            int factor2 = 3 * dp[p3];
            int factor3 = 5 * dp[p5];
            
            int mini = min({ factor1, factor2, factor3 });
            dp[i] = mini;
            
            if(factor1 == mini) p2++;
            if(factor2 == mini) p3++;
            if(factor3 == mini) p5++;
        }
        return dp[n];
    }
};