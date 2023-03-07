#define ll long long
class Solution {
public:
    bool check(vector<int>& time, ll total, ll givenTime) {
        ll possibleTrips = 0;
        for(int val: time) {
            possibleTrips += (givenTime / val);
            if(possibleTrips >= total) return true;
        }
        
        return possibleTrips >= total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll low = 0, high = 1e18;
        ll ans = high;
        while(low <= high) {
            ll mid = (low + high) / 2ll;
            
            if(check(time, totalTrips, mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};