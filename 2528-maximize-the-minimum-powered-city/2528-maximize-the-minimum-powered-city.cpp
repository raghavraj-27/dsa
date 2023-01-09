#define ll long long
class Solution {
public:
    bool check(vector<int>& s, ll mid, int r, int k) {
        int n = s.size();
        ll curr = 0;
        vector<ll> add(n, 0);
        
        for(int i=0; i<r; i++) curr += s[i];
        
        for(int i=0; i<n; i++) {
            if(i+r < n) {
                curr += s[i+r];
                curr += add[i+r];
            }
            if(curr <= mid) {
                ll need = mid - curr;
                if(need > k) return false;
                k -= need;
                curr = mid;
                add[min(n-1, i+r)] = need;
            }
            if(i-r >= 0) {
                curr -= s[i-r];
                curr -= add[i-r];
            }
        }
        
        return true;
    }
    long long maxPower(vector<int>& s, int r, int k) {
        int n = s.size();
        ll low = 0, high = accumulate(s.begin(), s.end(), 0ll) + k;
        ll res = INT_MIN;
        
        while(low <= high) {
            ll mid = (low + high) >> 1ll;
            
            if(check(s, mid, r, k)) {
                res = max(res, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return res;
    }
};