class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> arr; 
        int r = grid.size(), c = grid[0].size();
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                arr.push_back(grid[i][j]);
            }
        }
        
        k = k % arr.size();
        
        vector<vector<int>> ans(r, vector<int> (c));
        // vector<int> v;
        for(int i=arr.size()-k; i<arr.size(); i++) {
            arr.insert(arr.begin(), arr.back());
            arr.pop_back();
        }
        
        int p=0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                ans[i][j] = arr[p];
                p++;
            }
        }
        
        return ans;
    }
};