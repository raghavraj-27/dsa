class Solution {
public:
    bool isPossible(int barrier, vector<int>& weights, int days)
    {
        int w = 0, d = 1;
        for(int i=0; i<weights.size(); i++) {
            if(weights[i] > barrier) 
                return false;
            if((w + weights[i]) > barrier) {
                w = weights[i]; 
                d++;
            } else {
                w = w + weights[i];
            }
        }
        
        if(d > days)
            return false;
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int sum = 0; 
        for(auto val : weights) {
            sum += val;
        }
        if(days == 1) return sum;
        
        int low = 0, high = sum, res = -1; 
        while(low <= high) {
            int mid = (low + high) / 2; 
            
            if(isPossible(mid, weights, days)) 
            {
                res = mid; 
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return res;
    }
};