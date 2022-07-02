class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> temp = spells;
        sort(spells.rbegin(), spells.rend());
        
        map<int, int> ans;
        
        int i=0,j=0;
        for(; i<spells.size(); i++) {
            for(; j<potions.size(); j++) {
                long long val = (long long)((long long)spells[i] * (long long)potions[j]);
                
                if(val >= success) {
                    ans[spells[i]] = potions.size() - j;
                    // ans.push_back(potions.size() - j);
                    break;
                }
            }
            if(j >= potions.size()) {
                ans[spells[i]] = 0;
                // ans.push_back(0);
            }
        }
        
        vector<int> nums;
        for(int val : temp) {
            nums.push_back(ans[val]);
        }
        
        return nums;
    }
};