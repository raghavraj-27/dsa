class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2 == 0) {
            int num = 1;
            for(int i=0; i<n; i+=2) {
                ans.push_back(-1*num);
                ans.push_back(num);
                num++;
            }
            return ans;
        }
        
        int num = 1;
        for(int i=0; i<n-1; i+=2) {
            ans.push_back(-1*num);
            ans.push_back(num);
            num++;
        }
        ans.push_back(0);
        return ans;
    }
};