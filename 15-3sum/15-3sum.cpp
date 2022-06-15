class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    
    vector<vector<int>> ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());

    for(int i=0; i<n-2; i++) {
        int left = i+1;
        int right = n-1;

        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum + nums[i]==0) {
                vector<int>dp = {nums[i], nums[left], nums[right]};
                // dp[0]=nums[i];
                // dp[1]=nums[left];
                // dp[2]=nums[right];
                ans.push_back(dp);
                while(left < right and nums[right] == dp[2]) right--;
                while(left < right and nums[left] == dp[1]) left++;
            }
            else if(sum > -nums[i]) 
                right--;
            else 
                left++;
        }
        while(i < n-2 and nums[i] == nums[i+1]) 
            i++;
        
    }
    return ans;
}
};