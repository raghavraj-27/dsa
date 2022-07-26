class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size(), m = arr[0].size();
        for(int i=0; i<n; i++) {
            if(arr[i][0] <= target and target <= arr[i][m-1]) {
                for(int j=0; j<m; j++) {
                    if(target == arr[i][j]) {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};