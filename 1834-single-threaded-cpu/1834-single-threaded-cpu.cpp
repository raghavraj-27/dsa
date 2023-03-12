#define T pair<int, int>
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // this will store {processingTimei, indexi} of ith task
        priority_queue<T, vector<T>, greater<T>> pq;
        
        int n = tasks.size();
        for(int i=0; i<n; i++) {
            tasks[i].push_back(i);
        }
                                                      
        sort(begin(tasks), end(tasks));
        int i=0;
        long time = 0;
        
        vector<int> ans;
        while(i < n or not pq.empty()) {
            if(pq.empty()) {
                time = max(time, (long)tasks[i][0]);
            }
            while(i < n and tasks[i][0] <= time) {
                pq.emplace(tasks[i][1], tasks[i][2]);
                i++;
            }
            
            auto [processTime, index] = pq.top();
            pq.pop();
            ans.push_back(index);
            time += processTime;
        }
        
        
        return ans;
    }
};