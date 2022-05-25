bool cmp(vector<int>& v1, vector<int>& v2) {
    if(v1[1] < v2[1]) return true;
    return false;
}

class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sorting according to the end_i
        sort(intervals.begin(), intervals.end(), cmp);
        
        int ans = -1;
        vector<int> prev = intervals[0];
        
        for(vector<int> i : intervals) {
            if(prev[1] > i[0]) ans++;
            else prev = i;
        }
        
        return ans;
    }
};

// 1,2  1,3  2,3  3,4