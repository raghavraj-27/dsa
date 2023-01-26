class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        queue<pair<int, pair<int, int>>> pq;
        // {stops, {node, distance}}
        pq.push({0, {src, 0}});
        dist[src] = 0;
        
        while(pq.empty() == false) {
            int currStop = pq.front().first;
            int currNode = pq.front().second.first;
            int currDist = pq.front().second.second;
            pq.pop();
            
            if(currStop > k) continue;
            
            for(auto iter: adj[currNode]) {
                int nextNode = iter.first, nextDist = iter.second;
                if(dist[nextNode] > currDist + nextDist and currStop <= k) {
                    dist[nextNode] = currDist + nextDist;
                    pq.push({currStop + 1, {nextNode, dist[nextNode]}});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};