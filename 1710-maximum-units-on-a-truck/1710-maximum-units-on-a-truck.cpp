class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
//         double val1 = (double)v1[1] / v1[0];
//         double val2 = (double)v2[1] / v2[0];
        
//         if(val1 > val2) return true;
//         return false;
//         if(v1[0]*v1[1] > v2[0]*v2[1]) {
//             return true;
//         }
//         if(v1[0]*v1[1] == v2[0]*v2[1] and v1[0] < v2[0]) {
//             return true;
//         }
        if(v1[1] > v2[1]) {
            return true;
        }
        
        return false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        for(auto v : boxTypes) {
            cout<<"["<<v[0]<<","<<v[1]<<"] ";
        }
        cout<<endl;
        int ans = 0;
        
        for(int i=0; i<boxTypes.size(); i++) {
            if(boxTypes[i][0] < truckSize) {
                ans += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            } else if(truckSize > 0) {
                ans += (truckSize * boxTypes[i][1]);
                // return ans;
                truckSize = 0;
            } else {
                break;
            }
        }
        
        return ans;
    }
};
// 50 + 27 + 14