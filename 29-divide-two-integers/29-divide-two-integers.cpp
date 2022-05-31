class Solution {
public:
    int divide(int divident, int divisor) {
        cout<<INT_MIN<< " " <<INT_MAX;
        if(divident <= INT_MIN and divisor == 1) return INT_MIN;
        if(divident >= INT_MAX and divisor == 1) return INT_MAX;
        if(divident >= INT_MAX and divisor == -1) return INT_MIN;
        if(divident <= INT_MIN and divisor == -1) return INT_MAX;
        
        int res = 0;
        bool sign; 
        if(divident < 0 and divisor < 0) sign = true;
        if(divident < 0 and divisor > 0) sign = false;
        if(divident > 0 and divisor < 0) sign = false;
        if(divident > 0 and divisor > 0) sign = true;
        
        long dividend = abs(divident);
        long divisor_ = abs(divisor);
        
        while(dividend - divisor_ >= 0) {
            int count = 0;
            while((dividend - (divisor_ << 1 << count)) >= 0) {
                count++;
            }
            dividend -= (divisor_ << count);
            res += (1 << count);
        }
        
        if(sign) return res;
        return -1*res;
    }
};