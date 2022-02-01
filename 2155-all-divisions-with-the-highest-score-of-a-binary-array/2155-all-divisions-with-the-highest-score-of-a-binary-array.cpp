class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> cnt0(n), cnt1(n);
        for(int i=0; i<n; i++) {
            if(i==0) {
                cnt0[i] = (nums[i]==0 ? 1 : 0);
            } else {
                cnt0[i] = cnt0[i-1] + (nums[i]==0 ? 1 : 0);
            }
        }
        for(int j=n-1; j>=0; j--) {
            if(j==n-1) {
                cnt1[j] = (nums[j]==1 ? 1 : 0);
            } else {
                cnt1[j] = cnt1[j+1] + (nums[j]==1 ? 1 : 0);
            }
        }

        map<int, vector<int>> ans;
        int maxi=INT_MIN;
        ans[cnt1[0]].push_back(0);
        for(int i=0; i<n-1; i++) {
            int num = cnt0[i] + cnt1[i+1];
            ans[num].push_back(i+1);
        }
        ans[cnt0[n-1]].push_back(n);

        return ans.rbegin()->second;
    }
};