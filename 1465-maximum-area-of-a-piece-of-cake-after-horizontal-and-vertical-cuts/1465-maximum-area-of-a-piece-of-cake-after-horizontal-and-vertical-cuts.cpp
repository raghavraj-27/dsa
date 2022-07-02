class Solution {
public:
    int maxArea(int h, int w, vector<int>& hnums, vector<int>& vnums) {
        hnums.push_back(0); hnums.push_back(h);
        vnums.push_back(0); vnums.push_back(w);
        int mod = 1e9 + 7;
        
        sort(hnums.begin(), hnums.end());
        sort(vnums.begin(), vnums.end());
        
        int maxWidth = INT_MIN, maxHeight = INT_MIN;
        for(int i=1; i<hnums.size(); i++) {
            maxHeight = max(maxHeight, hnums[i] - hnums[i-1]);
        }
        
        for(int i=1; i<vnums.size(); i++) {
            maxWidth = max(maxWidth, vnums[i] - vnums[i-1]);
        }
        
        return ((long)(maxHeight % mod) * (long)(maxWidth % mod)) % mod;
    }
};