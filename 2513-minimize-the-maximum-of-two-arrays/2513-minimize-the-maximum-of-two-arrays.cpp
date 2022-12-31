class Solution {
public:
    int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
        long long low = 1, high = 1e15;
        long long lcm = ((long long) d1 * d2) / __gcd(d1, d2);
        long long res = -1;
        
        while(low <= high) {
            long long mid = (low + high) >> 1;
            
            if(d1 == d2) {
                long long c = mid - (mid / d1);
                if(c >= cnt1 + cnt2) {
                    res = mid;
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            } else {
                long long z1 = cnt1, z2 = cnt2;
                
                long long common = mid / lcm;
                long long c1 = mid / d1 - common;
                long long c2 = mid / d2 - common;
                long long total = mid - (c1 + c2 + common);
                
                z1 -= min(z1, c2);
                z2 -= min(z2, c1);
                
                if(z1 + z2 <= total) {
                    res = mid;
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
        }
        
        return res;
    }
};