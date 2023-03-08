class Solution {
public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         if(piles.size() == 1 and piles[0] < h)
//             return 1;
        
//         int low = 0, high = 1000000000, res = -1;
        
//         while(low < high)
//         {
//             int mid = (low + high) / 2; 
            
//             int cnt = 0;
//             for(int i=0; i<piles.size(); i++) {
//                 // cnt += (int)ceil((double)(piles[i] + mid - 1) / mid);
//                 cnt += (piles[i] + mid - 1) / mid;
//             }
                
//             if(h >= cnt) {
//                 high = mid;
//             } else {
//                 low = mid + 1;
//             }
//         }
        
//         return high;
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (int p : piles)
                total += (p + m - 1) / m;
            if (total > H)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
    
};