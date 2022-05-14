class Solution {
public:
    // BRUTE FORCE TC = O(n log n) + O(n^2), SC = O(1)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<int> temp(2, 0);
        
        
        for(int i=0; i<n ; i++){
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
            
            int j;
            for(j=i+1; j<n; j++){
                if(temp[1]>=intervals[j][0]){
                    if(temp[1]<intervals[j][1]){
                        temp[1] = intervals[j][1];
                    }
                }
                else
                    break;
            }
            ans.push_back(temp);
            i=j-1;
            
        }
        return ans;
    }
    
    // EFFICIENT APPROACH : TC = O(n log n) + O(n), SC = O(1)
    /*
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
    */
};