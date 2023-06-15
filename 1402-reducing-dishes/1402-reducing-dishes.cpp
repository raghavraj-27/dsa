class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int ans = 0;
        
        for(int i=0; i<s.size(); i++) {
            int p = 1, sum = 0; 
            for(int j=i; j<s.size(); j++) {
                sum += p * s[j];
                p++;
            }
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};