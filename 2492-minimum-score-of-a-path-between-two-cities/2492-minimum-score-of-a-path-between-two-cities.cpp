class DisjointSet {
    vector<int> rank, parent;
    public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);
        
        for(vector<int> v: roads) {
            int ai = v[0], bi = v[1];
            ds.unionByRank(ai, bi);
        }
        
        int ans = INT_MAX;
        for(vector<int> v: roads) {
            int ai = v[0], bi = v[1], dist = v[2];
            
            int ulp_1 = ds.findUltimateParent(1);
            int ulp_ai = ds.findUltimateParent(ai);
            int ulp_bi = ds.findUltimateParent(bi);
            if(ulp_ai == ulp_1 and ulp_bi == ulp_1) {
                ans = min(ans, dist);
            }
        }
        
        return ans;
    }
};