class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int low = 0, mid = piles.size()-2, high = piles.size()-1;
        
        int ans = 0;
        
        while(low < mid) {
            ans += piles[mid];
            low++;
            mid -= 2;
            high -= 2;
        }
        
        return ans;
    }
};