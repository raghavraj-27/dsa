class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0; i<queries.size(); i++) {
            int ai = queries[i][0], bi = queries[i][1];
            int heightAi, heightBi;
            for(int i=30; i>=0; i--) {
                if((1<<i) & ai) {
                    heightAi = i;
                    break;
                }
            }
            for(int i=30; i>=0; i--) {
                if((1<<i) & bi) {
                    heightBi = i;
                    break;
                }
            }
            
            
            int cai = ai, cbi = bi;
            while(cai != cbi) {
                if(cai > cbi) cai /= 2;
                else cbi /= 2;
            }
            int LCA = cai, heightLCA;
            for(int i=30; i>=0; i--) {
                if((1<<i) & LCA) {
                    heightLCA = i;
                    break;
                }
            }
            
            ans.push_back(heightAi + heightBi - 2*heightLCA + 1);
        }
        
        return ans;
    }
};