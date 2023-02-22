class Solution {
public:
    int minOperations(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int num = 1;
        while(2*num < n) {
            num = 2*num;
        }
        
        // int num = (1<<p);
        int target1 = 2*num - n;
        int target2 = n - num;
        
        int oprs1 = minOperations(target1);
        int oprs2 = minOperations(target2);
        return min(oprs1, oprs2) + 1;
    }
};