class Solution {
public:
    bool isPossible(int minForce, vector<int>& pos, int m) {
        int coord = pos[0], cnt = 1; 
        for(int i=1; i<pos.size(); i++) {
            if(pos[i] - coord >= minForce) {
                cnt++; 
                coord = pos[i];
            } 
            if(cnt == m)
                return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        int low = 1, high = pos[n-1] - pos[0];
        int res = -1;
        
        while(low <= high) {
            int mid = (low + high) >> 1; 
            
            if(isPossible(mid, pos, m)) {
                res = mid; 
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return res;
    }
};