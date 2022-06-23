class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        
        priority_queue<int> pq;
        int sum = 0;
        for(auto v : courses) {
            sum += v[0];
            pq.push(v[0]);
            
            if(sum > v[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};