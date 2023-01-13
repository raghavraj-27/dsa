class Solution {
public:
    int ans;
    vector<int> dist;
    void dfs(int node, int parent, vector<int> adj[], string& s) {
        dist[node] = 1;
        
        for(int i: adj[node]) {
            if(i != parent) {
                dfs(i, node, adj, s);
                if(s[i] != s[node]) {
                    ans = max(ans, dist[node] + dist[i]);
                    dist[node] = max(dist[node], 1 + dist[i]);
                }
            }
        }
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        ans = 1;
        dist.clear();
        dist.resize(n, 0);
        
        vector<int> adj[n];
        for(int i=1; i<n; i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        
        dfs(0, -1, adj, s);
        return ans;
    }
};