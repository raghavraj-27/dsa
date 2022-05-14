class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<int> temp(2, 0);
        
        
        for(int i=0; i<n ; i++){
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
            
            int j;
            // cout<<temp[0]<<" "<<temp[1]<<"|";
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
};