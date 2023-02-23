class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        
        for(int i=0; i<n; i++) {
            projects.push_back( {capital[i], profits[i]} );
        }
        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> pq;
        
        while(k--) {
            while(i < n and projects[i].first <= w) {
                pq.push(projects[i].second);
                i++;
            }
            
            if(pq.size() == 0) return w;
            
            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};