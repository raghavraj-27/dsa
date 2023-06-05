class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum = 0;
        reverse(queries.begin(), queries.end());
        set<int> r, c;
        
        for(auto it: queries) {
            if(it[0] == 0) {
                if(r.find(it[1]) == r.end()) {
                    sum += (n - c.size()) * it[2];
                    r.insert(it[1]);
                }
            } else {
                if(c.find(it[1]) == c.end()) {
                    sum += (n - r.size()) * it[2];
                    c.insert(it[1]);
                }
            }
        }
        
        return sum;
    }
};