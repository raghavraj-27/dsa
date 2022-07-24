class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int cnt = 0; 
        int ans = 1;
        vector<bool> vis(k+1, false);
        
        for(int i=0; i<rolls.size(); i++) {
            if(vis[rolls[i]] == false) {
                cnt++;
                vis[rolls[i]] = true;
            }
            
            if(cnt == k) {
                ans++;
                cnt = 0;
                for(int j=1; j<=k; j++) vis[j] = false;
            }
        }
        
        return ans;
    }
};