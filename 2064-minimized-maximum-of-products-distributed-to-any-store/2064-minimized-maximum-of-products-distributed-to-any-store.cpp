class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int low = 1, high = 1e5, ans = -1;
        
        while(low <= high) 
        {
            int mid = (low + high) >> 1; 
            
            int cnt = 0; 
            for(int i=0; i<q.size(); i++) {
                cnt = cnt + q[i] / mid;
                if(q[i]%mid)
                    cnt++;
            }
            
            if(cnt <= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};