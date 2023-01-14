class Solution {
public:
    int f(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        int ans = node;
        vis[node] = true;
        
        for(int i: adj[node]) {
            if(i != parent and vis[i] == false) {
                ans = min(ans, f(i, node, adj, vis));
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
//             bool flag = false;
            
//             for(int j=0; j<v.size(); j++) {
//                 if(v[j].find(ch1) != v[j].end() or v[j].find(ch2) != v[j].end()) {
//                     v[j].insert(ch1); v[j].insert(ch2);
//                     flag = true;
//                     break;
//                 }
//             }
            
//             if(flag == false) {
//                 set<char> s;
//                 s.insert(ch1); s.insert(ch2);
//                 v.push_back(s);
//             }
        }
        
        string ans = "";
        for(char ch: baseStr) {
            vector<bool> vis(26, false);
            ans = ans + (char) (97 + min(f(ch-'a', -1, adj, vis), ch-'a'));
            // bool flag = false;
            // for(int i=0; i<v.size(); i++) {
            //     if(v[i].find(ch) != v[i].end()) {
            //         ans = ans + (char)min((int)*v[i].begin(), (int)ch);
            //         flag = true;
            //         break;
            //     }
            // }
            // if(flag == false) ans = ans + ch;
        }
        
        return ans;
    }
};