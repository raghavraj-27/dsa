class Solution {
public:
    vector<int> ans;
    void add(vector<int>& v, vector<int>& mp) {
        for(int i=0; i<26; i++) {
            mp[i] += v[i];
        }
    }
    vector<int> dfs(int node, int parent, vector<int> adj[], string& labels) {
        vector<int> mp(26, 0);
        // mp[labels[node]]++;
        
        for(int i: adj[node]) {
            if(i != parent) {
                auto v = dfs(i, node, adj, labels);
                // ans[i] = v[labels[i] - 'a'];
                
                add(v, mp);
                // for(auto p: mp) {
                //     mp[p.first] += v[p.first];
                // }
            }
        }
        mp[labels[node] - 'a']++;
        
        ans[node] = mp[labels[node] - 'a'];
        
        return mp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.clear();
        ans.resize(n, 0);
        
        vector<int> adj[n];
        for(vector<int> v: edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        auto v = dfs(0, -1, adj, labels);
        // ans[0] = v[labels[0]];
        return ans;
    }
};