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
        
        for(int i: adj[node]) {
            if(i != parent) {
                auto v = dfs(i, node, adj, labels);
                add(v, mp);
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
        
        dfs(0, -1, adj, labels);
        return ans;
    }
};