class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> freq;
        for(int i=0; i<tasks.size(); i++) {
            freq[tasks[i]]++;
        }
        
        int round = 0;
        for(auto p: freq) {
            int f = p.second;
            int diff = p.first;
            
            if(f == 1) return -1;
            else if(f == 2) round++;
            else if(f == 3) round++;
            else if(f == 4) round += 2;
            else if(f % 3 == 2) {
                round = round + f / 3 + 1;
            } else if(f % 3 == 1) {
                round += (f-4) / 3 + 2;
            } else {
                round += f/3;
            }
        }
        
        return round;
    }
};