class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = true;
        
        for(int itr: adj[node]) {
            if(vis[itr] == false) {
                dfs(itr, adj, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size() < n-1) return -1;
        
        vector<bool> vis(n, false);
        
        vector<int> adj[n];
        for(auto v: c) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
//         cout<<cnt<<" ";
//         if(c.size() >= n-1) return 0;
        
//         if(c.size() > cnt - 1) return cnt - 1;
        return cnt-1;
    }
};
    
