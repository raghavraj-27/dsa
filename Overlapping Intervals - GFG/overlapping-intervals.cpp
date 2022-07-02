// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        pair<int, int> p = {intervals[0][0], intervals[0][1]};
        
        vector<vector<int>> ans;
        
        for(int i=1; i<intervals.size(); i++) {
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

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends