class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        pair<int, int> p;
        p.first = intervals[0][0]; p.second = intervals[0][1];
        vector<vector<int>> ans;
        int n = intervals.size();
        
        for(int i=1; i<intervals.size(); i++) {
            if(p.second >= intervals[i][0]) {
                p.first = min(intervals[i][0], p.first); 
                p.second = max(intervals[i][1], p.second); 
            } else {
                vector<int> v = {p.first, p.second}; 
                ans.push_back(v); 
                p.first = intervals[i][0]; 
                p.second = intervals[i][1];
            }
        }
        
        vector<int> v = {p.first, p.second}; 
        ans.push_back(v); 
        
        return ans;
    }
};