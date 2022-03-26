class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int total = 0;
        for(int i=0; i<costs.size(); i++) {
            total += costs[i][1];
        }
        
        multimap<int, pair<int, int>> mp;
        for(int i=0; i<costs.size(); i++) {
            // mp[costs[i][0] - costs[i][1]] = {costs[i][0], costs[i][1]};
            mp.insert({ costs[i][0] - costs[i][1], { costs[i][0], costs[i][1] } });
        }
        
        auto itr = mp.begin();
        for(int i=0; i<costs.size()/2; i++, itr++) {
            total += itr->second.first - itr->second.second;
        }
        return total;
    }
};
  // 2      4     -3      1
// a1,b1  a2,b2  a3,b3  a4,b4
// b1 + b2 + b3 + b4 = total

