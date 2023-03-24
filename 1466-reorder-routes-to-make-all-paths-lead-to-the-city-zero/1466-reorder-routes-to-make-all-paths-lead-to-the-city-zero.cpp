class Solution {
public:
    int calculateByBFS(int src, int n, vector<int> adj[], 
                       set<pair<int, int>> & given_roads) {
        vector<bool> vis(n, false);
        queue<int> q; 
        int count = 0;
        
        q.push(src); vis[src] = true; 
        
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            
            for(auto it : adj[node]) {
                if(vis[it] == false) {
                    if(given_roads.find({it, node}) == given_roads.end()) 
                        count++;
                    
                    vis[it] = true; 
                    q.push(it);
                }
            }
        }
        
        return count;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        set<pair<int, int>> given_roads; 
        for(auto v : connections) {
            given_roads.insert({v[0], v[1]});
        }
        
        vector<int> adj[n]; 
        for(auto v : connections) {
            adj[v[0]].push_back(v[1]); 
            adj[v[1]].push_back(v[0]);
        }
        
        return calculateByBFS(0, n, adj, given_roads);
    }
};