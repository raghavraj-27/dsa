class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        vector<pair<int, int>> ans;
        pair<int, int> p = {points[0][0], points[0][1]};
        
        for(int i=1; i<points.size(); i++) {
            int curr_start = points[i][0], curr_end= points[i][1];
            int prev_start = p.first, prev_end = p.second;
            
            if(prev_start <= curr_start and curr_start <= prev_end) {
                p = {max(prev_start, curr_start), min(prev_end, curr_end)};
            } else {
                ans.push_back(p);
                p = {curr_start, curr_end};
            }
        }
        ans.push_back(p);
        
        return ans.size();
    }
};