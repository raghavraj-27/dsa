class Solution {
public:
    static bool cmp(pair<int, int> p1, pair<int, int> p2) {
        return p1.first > p2.first;
    }
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        if(plant.size() == 1) {
            return plant[0] + grow[0];
        }
        vector<pair<int, int>> vec; 
        for(int i=0; i<plant.size(); i++) {
            vec.push_back({grow[i], plant[i]});
        }
        
        sort(vec.begin(), vec.end(), cmp); 
        int sum = 0;
        int lim = 0;
        int i =0; 
        for(i=0; i<grow.size(); i++) {
            sum += vec[i].second;
            lim = max(lim, sum + vec[i].first);
        }
        // sum += vec[i].first + vec[i].second;
        // lim = max(lim, sum + vec[i].first);
        
        return lim;
    }
};

// 0123456789
// .xxX      
//  ..xX     
//    ...xxX 
//       ..xX

