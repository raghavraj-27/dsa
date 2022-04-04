class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp1, mp2;
        set<int> s;
        for(int i=0; i<matches.size(); i++) {
            vector<int> v = matches[i];
            mp1[v[0]]++; mp2[v[1]]++;
            s.insert(v[0]); s.insert(v[1]);
        }
        
        vector<vector<int>> ans;
        vector<int> v1, v2;
        for(auto val : s) {
            if(mp2[val] == 0) {
                v1.push_back(val);
            } else if(mp2[val] == 1) {
                v2.push_back(val);
            }
        }
        
        ans.push_back(v1); ans.push_back(v2);
        
        return ans;
    }
};