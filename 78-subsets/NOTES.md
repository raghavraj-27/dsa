Recursive way to solve
```
class Solution {
public:vector<vector<int>> ans;
void subsets(int i, vector<int>& nums, vector<int>& v) {
if(i>=nums.size()) {
ans.push_back(v);
return;
}
v.push_back(nums[i]);
subsets(i+1, nums, v);
v.pop_back();
subsets(i+1, nums, v);
}
vector<vector<int>> subsets(vector<int>& nums) {
vector<int> v;
subsets(0, nums, v);
return ans;
}
};
```