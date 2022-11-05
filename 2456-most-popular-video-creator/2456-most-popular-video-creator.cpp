class Solution {
public:
    
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) {
        map<string, int> mp;
        map<string, map<int, set<string>>> ip;
        int n = c.size();
        
        for(int i=0; i<n; i++) {
            mp[c[i]] += views[i];
            ip[c[i]][views[i]].insert(ids[i]);
        }
        
        vector<vector<string>> ans;
        int hh = INT_MIN;
        for(auto p: mp) {
            hh = max(hh, p.second);
        }
        
        for(auto p: mp) {
            if(p.second == hh) {
                int sz = 0;
                string v = "zzzzzzzzzz";
                
                map<int, set<string>> m = ip[p.first];
                int mx_sz = 0;
                int mx_view = 0;
                for(auto q: m) {
                    // mx_sz = max((int)q.second.size(), (int)mx_sz);
                    mx_view = max((int)q.first, (int)mx_view);
                }
                
                // for(auto q: m) {
                //     if(mx_sz == q.second.size()) {
                //         // sz = q.second.size();
                //         v = min(*q.second.begin(), v);
                //     }
                // }
                
                
                ans.push_back({p.first, *m[mx_view].begin()});
                // ans.push_back({p.first, v});
            }
        }
        
        return ans;
    }
};