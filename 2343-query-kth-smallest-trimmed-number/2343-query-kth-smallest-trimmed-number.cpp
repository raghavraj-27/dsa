class Solution {
public:
    static bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    }
    int getKth(vector<string>& nums, int k, int t) {
        vector<pair<string, int>> v;
        
        for(int i=0; i<nums.size(); i++) {
            string str = nums[i].substr(nums[i].size()-t, t);
            v.push_back({str, i});
        }
        
        sort(v.begin(), v.end(), [](pair<string, int>& p1, pair<string, int>& p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        });
        return v[k-1].second;
    }
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        for(int i=0; i<q.size(); i++) {
            ans.push_back(getKth(nums, q[i][0], q[i][1]));
        }
        return ans;
    }
};