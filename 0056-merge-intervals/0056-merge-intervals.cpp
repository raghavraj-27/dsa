class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        pair<int, int> p = {intervals[0][0], intervals[0][1]};
        
        for(int i=1; i<n; i++) {
            if(p.second >= intervals[i][0]) {
                p.second = max(p.second, intervals[i][1]);
            } else {
                ans.push_back({p.first, p.second});
                p = {intervals[i][0], intervals[i][1]};
            }
        }
        
        ans.push_back({p.first, p.second});
        
        return ans;
    }
};