class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<int> v;
        for(int i=0; i<=n; i++) {
            v.push_back(i+1);
        }
        
        while(1) {
            bool flag = true;
            
            for(int i=0; i<n; i++) {
                if(pattern[i] == 'I' and v[i+1] > v[i]) {
                    
                } else if(pattern[i] == 'D' and v[i+1] < v[i]) {
                    
                } else {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                string ans = "";
                for(int i=0; i<=n; i++) {
                    ans += ('0' + v[i]);
                }
                return ans;
            }
            
            next_permutation(v.begin(), v.end());
        }
        
        return "";
    }
};