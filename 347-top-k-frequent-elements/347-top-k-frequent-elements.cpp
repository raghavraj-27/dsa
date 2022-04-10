class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(auto val : nums) {
            freq[val]++;
        }
        
        priority_queue<pair<int, int>> q;
        for(auto mp : freq) {
            q.push({mp.second,mp.first});
        }
        
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};