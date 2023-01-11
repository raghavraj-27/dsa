class Solution {
public:
    int ans;
    pair<int, int> dfs(int node, int parent, vector<int> adj[], vector<bool>& hasApple) {
        pair<int, int> v = {0, hasApple[node]};
        
        for(int i: adj[node]) {
            if(i != parent) {
                auto p = dfs(i, node, adj, hasApple);
                v.first += (p.first + 2) * p.second;
                v.second = v.second or p.second;
            }
        }
        return v;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(vector<int> v: edges) {
            int ai = v[0], bi = v[1];
            adj[ai].push_back(bi);
            adj[bi].push_back(ai);
        }
        
        return dfs(0, -1, adj, hasApple).first;
        // return ans;
    }
};