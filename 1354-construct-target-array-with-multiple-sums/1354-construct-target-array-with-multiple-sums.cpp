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
            // if(curr)
            sum -= curr_max;
            
            // int diff = curr_max - sum;
            if(sum == 1 or curr_max == 1) return true;
            if(sum > curr_max or sum == 0 or curr_max%sum == 0)
                return false;
            // if(diff == 0) {
            //     return false;
            // }
            
            // if(diff > 1) {
                pq.push(curr_max % sum);
                
            // }
            sum += (curr_max % sum);
            
            // if(pq.empty() == true or pq.top() == 1) break;
        }
        
        return true;
    }
};