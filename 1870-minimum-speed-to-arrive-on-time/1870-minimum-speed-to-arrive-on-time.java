class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        int low = 1, high = 1000000000;
        int res = -1;
        int n = dist.length;
        
        while(low < high) {
            int mid = (low + high) >> 1;
            
            double time = 0;
            for(int i=0; i<n; i++) {
                time = Math.ceil(time) + (dist[i] / (double) mid);
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
}