class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int len = n - k;
        
        int sum = 0, min_sum = INT_MAX;
        for(int i=0; i<n; i++) {
            if(i < len) {
                sum += cardPoints[i];
            }
            
            if(i >= len) {
                min_sum = min(min_sum, sum);
                sum += cardPoints[i] - cardPoints[i-len];
            }
        }
        
        min_sum = min(min_sum, sum);
        
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        return total - min_sum;
    }
};