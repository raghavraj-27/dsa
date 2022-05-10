class Solution {
public:
    void solve(int i, vector<int>& arr, int k, int sum, vector<int>& v, vector<vector<int>>& ans) {
        if(sum == 0 and k == 0) {
            ans.push_back(v);
        }
        if(sum < 0 or i >= arr.size() or k < 0) return;
        
        for(int ind = i; ind<arr.size(); ind++) {
            v.push_back(arr[ind]);
            solve(ind+1, arr, k-1, sum-arr[ind], v, ans);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        
//         int sum = 0; 
//         for(int i=0; i<k; i++) {
//             sum += arr[i];
//         }
        
//         if(sum > n) return ans;
        
        vector<int> v;
        solve(0, arr, k, n, v, ans);
        return ans;
    }
};