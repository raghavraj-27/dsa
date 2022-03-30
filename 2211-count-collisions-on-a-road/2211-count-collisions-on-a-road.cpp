class Solution {
public:
    int countCollisions(string d) {
        int cntR = 0, ans = 0;
        for(int i=0; i<d.size(); i++) {
            if(d[i] == 'R') cntR++;
            if(d[i] == 'L' or d[i] == 'S') {
                ans += cntR;
                cntR = 0;
            }
        }
        
        int cntL = 0;
        for(int i=d.size()-1; i>=0; i--) {
            if(d[i] == 'L') cntL++;
            if(d[i] == 'S' or d[i] == 'R') {
                ans += cntL;
                cntL = 0;
            }
        }
        
        return ans;
    }
};