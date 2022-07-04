class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(); 
        vector<int> cnt(n, 1);
        
        for(int i=0; i<n-1; i++) {
            if(ratings[i+1] > ratings[i]) {
                cnt[i+1] = cnt[i] + 1;
            }
        }
        
        for(int i=n-1; i>0; i--) {
            if(ratings[i-1] > ratings[i]) {
                if(cnt[i-1] < (cnt[i]+1))
                    cnt[i-1] = cnt[i]+1;
            }
        }
        
        // if(ratings[0] > ratings[1]) cnt[0]++;
        // if(ratings[n-1] > ratings[n-2]) cnt[n-1]++;
        
        int sum = accumulate(cnt.begin(), cnt.end(), 0);
        return sum;
    }
};