class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int val: stones) {
            pq.push(val);
        }
        
        while(pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            
            if(x == y) continue;
            
            y = y - x;
            pq.push(y);
        }
        
        if(pq.size() == 0) return 0;
        
        return pq.top();
    }
};