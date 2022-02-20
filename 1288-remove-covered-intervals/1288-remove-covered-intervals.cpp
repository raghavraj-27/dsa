class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        int left = -1, right = -1, res = 0;
        for(auto & v : A) {
            if(v[0] > left and v[1] > right) {
                left = v[0];
                res++;
            }
            right = max(right, v[1]);
        }
        
        return res;
    }
};