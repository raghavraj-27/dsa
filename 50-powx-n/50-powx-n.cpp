class Solution {
public:
    double f(double x, long n) {
        if(n == 0) return 1.0;
        
        if(n % 2 == 0) {
            return f(x*x, n / 2);
        }
        
        return x * f(x, n-1);
    }
    
    double myPow(double x, int n) {
        double a = f(x, abs(n));
        
        if(n > 0) 
            return a;
        return 1 / a;
    }
};