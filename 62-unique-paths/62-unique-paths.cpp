class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int R = m-1;
        long res = 1;
        for(int i=1; i<=R; i++) {
            res = res * (N-R+i) / i;
        }
        return res;
    }
};

// 8C4 = 1.2.3.4. 5.6.7.8
//       1.2.3.4  1.2.3.4
      