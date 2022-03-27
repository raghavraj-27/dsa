class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int, int> mp1, mp2, dup;
        set<int> s;
        int n = tops.size();
        
        for(int i=0; i<n; i++) {
            s.insert(tops[i]);
            s.insert(bottoms[i]);
            mp1[tops[i]]++;
            mp2[bottoms[i]]++;
            if(tops[i] == bottoms[i]) {
                dup[tops[i]]++;
            }
        }
        
        int ans = INT_MAX;
        for(auto it=s.begin(); it!=s.end(); it++) {
            int num = *it;
            if((mp1[num] + mp2[num] - dup[num]) == n) {
                // int opr_req = abs(mp1[num] - mp2[num]) - dup[num];
                int opr_req = min(mp1[num], mp2[num]) - dup[num];
                ans = min(ans, opr_req);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};