// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int count(int node, vector<int> adj[], int n, vector<bool>& vis, int d) {
        // vis[node] = true;
        if(node == d) {
            return 1;
        }
        
        int ans = 0;
        for(auto val : adj[node]) {
            // if(vis[val] == false) {
                ans += count(val, adj, n, vis, d);
            // }
        }
        
        return ans;
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<int> adj[n];
	    for(auto p : edges) {
	        adj[p[0]].push_back(p[1]);
	    }
	    
	    vector<bool> vis(n, false);
	    
	    return count(s, adj, n, vis, d);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends