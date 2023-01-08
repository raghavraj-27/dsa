class Solution {
public:
    float slope(float x1, float y1, float x2, float y2) {
        if (x2 - x1 != 0)
            return (y2 - y1) / (x2 - x1);
        return 1000000000.0;
    }
    int maxPoints(vector<vector<int>>& points) {
        // map<float, set<vector<int>>> ans;
        // map<int, set<vector<int>>> foo, boo;
        int n = points.size();
        if(n < 3) return n;
        // sort(points.begin(), points.end());
        int ans = 1;
        for(int i=0; i<n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=0; j<n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int total = 2;
                for(int k=0; k<n; k++) {
                    int x3 = points[k][0], y3 = points[k][1];
                    if(i == j or j == k or i == k) continue;
                    if(slope(x1,y1,x2,y2) == slope(x2,y2,x3,y3)) total++;
                }
                
                ans = max(ans, total);
            }
        }
        return ans;
//         int a = 1;
//         for(auto p: ans) {
//             // for(set<int> s: p.second) {
//                 // for(vector<int> v: p.second) {
//                 //     cout<<"["<<v[0]<<","<<v[1]<<"] ";
//                 // }
//                 // cout<<endl;
//             // }
//             a = max(a, (int)p.second.size());
//         }
//         for(auto p: foo) {
//             a = max(a, (int)p.second.size());
//         }
//         for(auto p: boo) {
//             a = max(a, (int)p.second.size());
//         }
        
//         return a;
    }
};