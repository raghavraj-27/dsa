class Solution {
public:
    
    vector<int> search(vector<pair<int, int>> adj[], int n) {
        vector<int> dist(n, -1);
        dist[0] = 0;
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, -1}});
        
        vector<vector<int>> vis(n, vector<int> (2, 0));
        vis[0][0] = 1;
        vis[0][1] = 1;
        
        while(not pq.empty()) {
            int currDist = pq.front().first;
            int currNode = pq.front().second.first;
            int prevColor = pq.front().second.second;
            pq.pop();
            
            for(auto p: adj[currNode]) {
                int nextNode = p.first;
                int color = p.second;
                
                if(vis[nextNode][color] == 0 and prevColor != color) {
                    if(dist[nextNode] == -1)
                        dist[nextNode] = currDist + 1;
                    pq.push({currDist + 1, {nextNode, color}});
                    vis[nextNode][color] = 1;
                }
            }
        }
        
        return dist;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adj[n];
        for(auto v: redEdges) {
            adj[v[0]].push_back({v[1], 0});
        }
        for(auto v: blueEdges) {
            adj[v[0]].push_back({v[1], 1});
        }
        
        return search(adj, n);
    }
};