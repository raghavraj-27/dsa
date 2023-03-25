#define ll long long
class Solution {
public:
    ll dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        long long cnt = 1;
        
        for(int itr: adj[node]) {
            if(vis[itr] == false)
            cnt += dfs(itr, adj, vis);
        }
        
        return cnt;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<ll> v;
        vector<bool> vis(n, false);
        
        vector<vector<int>> adj(n);
        for(auto v : edges) {
            int ai = v[0], bi = v[1];
            adj[ai].push_back(bi);
            adj[bi].push_back(ai);
        }
        
        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                ll noOfNodes = dfs(i, adj, vis);
                v.push_back(noOfNodes + (v.size() ? v.back() : 0));
                // cout<<v.back()<<" ";
            }
            
        }
        
        ll ans = 0ll;
        for(int i=1; i<v.size(); i++) {
            ans += (v[i] - v[i-1]) * v[i-1];
            // for(int j=i+1; j<v.size(); j++) {
            //     ans += v[i] * v[j];
            // }
        }
        
        return ans;
    }
};