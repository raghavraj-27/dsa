class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(), target.end());
        long sum = 0;
        for(int a : target) {
            sum += a;
        }
        
        while(true) {
            int curr_max = pq.top(); pq.pop();
            sum -= curr_max;
            
            if(sum == 1 or curr_max == 1) break;
            if(sum > curr_max or sum == 0 or curr_max%sum == 0) return false;
            
            pq.push(curr_max % sum);
            sum += (curr_max % sum);
        }
        
        return true;
    }
};