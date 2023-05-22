class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 
        for(int val: nums) {
            freq[val]++;
        }
        
        vector<vector<int>> bucket(nums.size()+1);
        for(auto [a, b]: freq) {
            bucket[b].push_back(a);
        }
        
        vector<int> res;
        for(int i=nums.size(); k; i--) {
            for(int val: bucket[i]) {
                res.push_back(val);
                k--;
            }
        }
        
        return res;
    }
};