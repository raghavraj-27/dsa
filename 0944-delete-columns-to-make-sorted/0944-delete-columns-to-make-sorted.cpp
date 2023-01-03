class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<vector<char>> m(strs[0].size(), vector<char> (strs.size()));
        int cnt = 0;
        
        for(int i=0; i<strs[0].size(); i++) {
            for(int k=0, j=0; j<strs.size(); j++) {
                m[i][k] = strs[j].at(i);
                k++;
            }
            
            if(not is_sorted(m[i].begin(), m[i].end())) {
                cnt++;
            }
        }
        
        return cnt;
    }
};