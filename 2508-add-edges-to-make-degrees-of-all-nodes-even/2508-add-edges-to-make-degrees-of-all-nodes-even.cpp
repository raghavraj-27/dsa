class Solution {
public:
    bool check(set<int> adj[], vector<int>& odds, vector<int>& inorder, int n) {
        if(odds.size() == 2) {
            for(int i=1; i<=n; i++) {
                if(adj[odds[0]].find(i) == adj[odds[0]].end() and adj[odds[1]].find(i) == adj[odds[1]].end()) {
                    return true;
                }
            }
            return false;
        }
        return (adj[odds[0]].find(odds[1]) == adj[odds[0]].end() and adj[odds[2]].find(odds[3]) == adj[odds[2]].end()) or
               (adj[odds[0]].find(odds[2]) == adj[odds[0]].end() and adj[odds[1]].find(odds[3]) == adj[odds[1]].end()) or
               (adj[odds[0]].find(odds[3]) == adj[odds[0]].end() and adj[odds[1]].find(odds[2]) == adj[odds[1]].end());
    }
    bool isPossible(int n, vector<vector<int>>& edges) {
        set<int> adj[n+1];
        vector<int> inorder(n+1);
        // cout<<edges.size()<<endl;
        for(int i=0; i<edges.size(); i++) {
            int ai = edges[i][0], bi = edges[i][1];
            adj[ai].insert(bi);
            adj[bi].insert(ai);
            inorder[ai]++;
            inorder[bi]++;
        }
        
        vector<int> odds;
        for(int i=1; i<=n; i++) {
            if(inorder[i] % 2 != 0) {
                odds.push_back(i);
            }
        }
        // cout<<odds.size()<<endl;
        if(odds.size() == 0) return true;
        
        if(odds.size()==2 or odds.size()==4) {
            return check(adj, odds, inorder, n);
        }
        return false;
    }
};