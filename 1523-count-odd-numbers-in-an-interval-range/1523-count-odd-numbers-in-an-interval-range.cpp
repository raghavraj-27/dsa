class Solution {
public:
    int countOdds(int low, int high) {
        if(low % 2 and high % 2) {
            return (high - low) / 2 + 1;
        }
        if(low % 2 == 0 and high % 2 == 0) {
            return (high - low) / 2;
        }
        return ceil((high - low) / 2.0);
    }
};

// 3,5,7 = 3 (7-3)/2 + 1
//     10,14 (11,13) [14-10 / 2]
    
//     10,15 (11,13,15)