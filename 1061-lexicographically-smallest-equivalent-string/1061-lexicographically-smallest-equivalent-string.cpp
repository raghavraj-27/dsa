class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        int ans = node;
        vis[node] = true;
        
        for(int i: adj[node]) {
            if(i != parent and vis[i] == false) {
                ans = min(ans, dfs(i, node, adj, vis));
            }
        }
        
        return ans;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> adj(26);
        int n = s1.size(); 
        
        for(int i=0; i<n; i++) {
            char ch1 = s1[i], ch2 = s2[i];
            adj[ch1-'a'].push_back(ch2-'a');
            adj[ch2-'a'].push_back(ch1-'a');
        }
        
        string ans = "";
        for(char ch: baseStr) {
            vector<bool> vis(26, false);
            ans = ans + (char) (97 + min(dfs(ch-'a', -1, adj, vis), ch-'a'));
        }
        
        return ans;
    }
};