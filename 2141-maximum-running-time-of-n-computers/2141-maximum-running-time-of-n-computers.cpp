class Solution {
public:
    bool isPossibleToRun(long long maxLmt, vector<int>&batt, int n)
    {
        long long tot = (long long)(maxLmt*n); 
        long long cnt = 0;
        for(auto val : batt) {
            cnt += min((long long)val, maxLmt);
        }
        
        if(cnt >= tot)
            return true;
        return false;
    }
    long long maxRunTime(int n, vector<int>& batt) {
        long long sum = 0; 
        for(auto it : batt) {
            sum += it;
        }
        long long low = 1, high = sum;
        long long res = -1;
        while(low <= high) {
            long long mid = (low + high) >> 1; 
            if(isPossibleToRun(mid, batt, n)) {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid-1;
        }
        return res;
    }
};