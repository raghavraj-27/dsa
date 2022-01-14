class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size() == 1 and piles[0] < h)
            return 1;
        
        int low = 0, high = *max_element(piles.begin(), piles.end()), res = -1;
        
        while(low <= high)
        {
            int mid = (low + high) / 2; 
            
            int cnt = 0;
            for(int i=0; i<piles.size(); i++) {
                cnt += (int)ceil((double)piles[i] / mid);
            }
                
            if(h >= cnt) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return res;
    }
};