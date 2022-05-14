class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(vector<int> v : times) {
            int s = v[0], t = v[1], time = v[2];
            adj[s].push_back({t, time});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> timeTo(n+1, INT_MAX);
        
        pq.push({0, k});
        timeTo[k] = 0;
        
        while(not pq.empty()) 
        {
            int prev_node = pq.top().second;
            int prev_time = pq.top().first;
            pq.pop();
            
            for(auto p: adj[prev_node]) {
                int next_node = p.first;
                int next_time = p.second;
                if(timeTo[next_node] > prev_time + next_time) {
                    timeTo[next_node] = prev_time + next_time;
                    pq.push({timeTo[next_node], next_node});
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=1; i<=n; i++) {
            ans = max(ans, timeTo[i]);
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};