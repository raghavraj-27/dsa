class Solution {
public:
    int lower(vector<int> v, int q) {
        int ans = 0, ind = 0;
        int low = 0, high = v.size()-1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(v[mid] <= q) {
                if(ans < v[mid]) {
                    ans = v[mid];
                    ind = mid;
                }
                // ans = max(ans, v[mid]);
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return ind;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            sort(grid[i].begin(), grid[i].end());
        }
        
        int ans = 0;
        
        for(int i=0; i<m; i++) {
            int ind = upper_bound(grid[i].begin(), grid[i].end(), -1) - grid[i].begin();
//             while(ind < grid[i].size()) {
//                 if(grid[i][ind] == -1) ind++;
//                 else break;
                
//             }
            ans += ind;
            // int ind = lower(grid[i], 0);
            // if(grid[i][ind] < 0) {
            //     ans = ans + ind + 1;
                // cout<<grid[i][ind]<< " ";
            // }
        }
        
        return ans;
    }
};