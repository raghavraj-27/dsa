class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, vector<string>> adj; 
        unordered_map<string, int> indegree;
        
        for(int i=0; i<n; i++) {
            for(auto s : ingredients[i]) {
                adj[s].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        
        vector<string> ans;
        queue<string> q;
        for(auto item : supplies) {
            if(indegree[item] == 0) {
                q.push(item);
            }
        }
        
        while(not q.empty()) {
            string node = q.front(); q.pop(); 
            for(auto s : adj[node]) {
                indegree[s]--;
                if(indegree[s] == 0) {
                    q.push(s);
                }
            }
        }
        
        for(auto s : recipes) {
            if(indegree[s] == 0) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};