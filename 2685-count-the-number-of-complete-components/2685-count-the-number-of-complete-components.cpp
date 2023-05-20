class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int& cntNode, int& cntEdge) {
        vis[node] = true;
        cntNode++;
        
        for(int ele: adj[node]) {
            cntEdge++;
            if(vis[ele] == false) {
                
                dfs(ele, adj, vis, cntNode, cntEdge);
            }
        }
    }
//     bool isCompleteComponent(int node, vector<vector<int>>& adj) {
        
//     }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(vector<int> v: edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        // vector<int> components;
        vector<bool> vis(n, false);
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                int cntNode = 0, cntEdge = 0;
                dfs(i, adj, vis, cntNode, cntEdge);
                // cout<<i<<" - NodeOfNodes = "<<cntNode<<" NoOfEdges = "<<cntEdge<<"\n";
                if(cntEdge / 2 == cntNode*(cntNode - 1) / 2) {
                    
                    cnt++;
                }
                // components.push_back(i);
            }
        }
        
//         for(int node: components) {
//             if(isCompleteComponent(node, adj)) {
//                 cnt++;
//             }
//         }
        
        return cnt;
    }
};