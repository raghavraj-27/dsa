class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = n-1;
        double res = 1;
        
        for(int i=0; i<r; i++) {
            res = res*(N-r+i+1) / (i+1);
        }
        
        return (int)res;
    }
};