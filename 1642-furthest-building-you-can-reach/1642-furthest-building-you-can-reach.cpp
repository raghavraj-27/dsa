class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // min-hep
        priority_queue <int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<heights.size()-1; i++) {
            int diff = heights[i+1] - heights[i];
            
            if(diff > 0) {
                if(pq.size() < ladders) {
                    pq.push(diff);
                } else {
                    int br = diff;
                    // In this case, we are preparing to use the brick for thevery first smallest height
                    if(pq.size() > 0 and pq.top() < diff) {
                        br = pq.top(); pq.pop();
                        pq.push(diff);
                    }
                    
                    // I will try to use brick and if I won't be able to use,this is the destination building
                    if(bricks-br >= 0) {
                        bricks = bricks - br;
                    } else {
                        return i;
                    }
                }
            }
        }
        
        return heights.size()-1;
    }
};