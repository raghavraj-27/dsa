class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        if(v1[0] < v2[0]) return true;
        if(v1[0] == v2[0]) {
            if(v1[1] < v2[1]) return true;
        }
        
        return false;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), cmp);
        
        vector<vector<int>> ans(p.size(), vector<int> (2, -1));
        for(int i=0; i<p.size(); i++) {
            int count = p[i][1];
            vector<int> v = {-1, -1};
            
            for(int j=0; j<p.size(); j++) {
                if(ans[j] == v and count == 0) {
                    ans[j] = p[i];
                    break;
                } else if(ans[j] == v or ans[j][0] >= p[i][0]) {
                    count--;
                }
            }
        }
        
        return ans;
    }
};