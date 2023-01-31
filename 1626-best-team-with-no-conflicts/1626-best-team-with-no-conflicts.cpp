class Solution {
public:
    // int dp[1001];
//     int dp[1002][1000002];
//     // unordered_map<string, int> mp;
//     bool checkConflict(int agesi, int scorei, int agesj, int scorej) {
//         if(agesi < agesj and scorei > scorej) return true;
//         if(agesi > agesj and scorei < scorej) return true;
//         return false;
//     }
//     int f(int ind, vector<pair<int, int>>& vpi, int prevAge, int prevScore) {
//         if(ind < 0) return 0;
        
//         int currAge = vpi[ind].first, currScore = vpi[ind].second;
//         // string key = to_string(ind) + "-" + to_string(prevAge) + "-" + to_string(prevScore);
        
//         if(dp[prevAge][prevScore] != -1) return dp[prevAge][prevScore];
//         // if(mp.find(key) != mp.end()) return mp[key];
//         // if(dp[ind] != -1) return dp[ind];
//         int take = -10000;
//         if(not checkConflict(prevAge, prevScore, currAge, currScore)) {
//             take = currScore + f(ind-1, vpi, currAge, currScore);
//         }
        
//         int notTake = f(ind-1, vpi, prevAge, prevScore);
        
//         return dp[prevAge][prevScore] = max(take, notTake);
//         // return mp[key] = max(take, notTake);
//         // return dp[ind] = max(take, notTake);
//     }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> vpi;
        // memset(dp, -1, sizeof(dp));
        
        for(int i=0; i<n; i++) {
            vpi.push_back(make_pair(ages[i], scores[i]));
        }
        
        sort(vpi.begin(), vpi.end());
        vector<int> ans(n);
        
        for(int i=0; i<n; i++) {
            ans[i] = vpi[i].second;
            
            for(int j=0; j<i; j++) {
                if(vpi[j].second <= vpi[i].second)
                ans[i] = max(ans[i], ans[j] + vpi[i].second);
            }
        }
        
        return *max_element(ans.begin(), ans.end());
    }
};

/*
player i and j will have confilict 
if ages[i] < ages[j] and score[i] > score[j]
if ages[i] > ages[j] and score[i] < score[j]
*/