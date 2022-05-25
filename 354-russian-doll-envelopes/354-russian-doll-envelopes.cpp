bool cmp(vector<int>& v1, vector<int>& v2) {
    if(v1[0] == v2[0] and v1[1] > v2[1]) return true;
    if(v1[0] < v2[0]) return true;
    
    return false;
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), cmp);
        
        vector<int> lis;
        for(int i=0; i<env.size(); i++) {
            int ind = lower_bound(lis.begin(), lis.end(), env[i][1]) - lis.begin();
            
            if(ind >= lis.size()) lis.push_back(env[i][1]);
            else lis[ind] = env[i][1];
        }
        
        return lis.size();
    }
};

// [[4,5],[4,6],[6,7],[2,3],[1,1]]
// [1,1], [2,3], [4,5], [4,6], [6,7]

