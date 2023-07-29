class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1000000000;
        int res = -1;
        int n = dist.size();
        
        while(low < high) {
            int mid = (low + high) >> 1;
            
            double time = 0;
            for(int i=0; i<n; i++) {
                time = ceil(time) + (dist[i] / (double) mid);
            }
            
            if(time <= hour) {
                // cout<<time<<" ";
                res = mid;
                high = mid;
            } else {
                low = mid+1;
            }
        }
        
        return res;
    }
};