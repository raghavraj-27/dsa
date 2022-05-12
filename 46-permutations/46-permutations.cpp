class Solution {
public:
    // TC : n! * n SC : O(n)
//     void createPermutations(vector<int>& nums, vector<int> &v, vector<vector<int>>& ans,
//                            map<int, bool> & freq)
//     {
//         if(v.size()>=nums.size()) {
//             ans.push_back(v); 
//             return;
//         }
        
//         for(int ind=0; ind<nums.size(); ind++) {
//             if(freq[ind] == false) {
//                 freq[ind] = true; 
//                 v.push_back(nums[ind]); 
//                 createPermutations(nums, v, ans, freq); 
//                 freq[ind] = false; 
//                 v.pop_back();
//             }
//         }
//     }
    
    
    // TC : O(n! x n) SC : O(1)
    void createPermutations(int ind, vector<int> & nums, vector<vector<int>> & ans)
    {
        if(ind >= nums.size()) {
            ans.push_back(nums); 
            return;
        }
        
        for(int i=ind; i<nums.size(); i++) {
            swap(nums[i], nums[ind]); 
            createPermutations(ind+1, nums, ans); 
            swap(nums[i], nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
//         vector<int> v; 
//         map<int, bool> freq;
        
//         for(int i=0; i<nums.size(); i++) {
//             freq[i] = false;
//         }
        
        // createPermutations(nums, v, ans, freq);         
        createPermutations(0, nums, ans); 

        return ans;
    }
};