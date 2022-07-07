class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x = jug1Capacity, y = jug2Capacity;
        int tot = x + y;
        vector<int> d = {x, -1*x, y, -1*y};
        
        queue<int> q;
        vector<bool> vis(tot + 1, false);
        q.push(0);
        
        while(not q.empty()) {
            int node = q.front(); q.pop();
            vis[node] = true;
            
            if(node == targetCapacity) {
                return true;
            }
            
            for(int i=0; i<4; i++) {
                int newnode = node + d[i];
                if(newnode >=0 and newnode <= tot and vis[newnode] == false) {
                    q.push(newnode);
                }
            }
        }
        
        return false;
    }
};