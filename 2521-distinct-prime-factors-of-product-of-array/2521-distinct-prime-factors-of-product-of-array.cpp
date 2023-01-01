class Solution {
public:
    set<long long> primeFactors(long long n) 
    { 
        set<long long> ans;
        // Print the number of 2s that divide n 
        while (n%2 == 0) 
        { 
            // printf("%d ", 2); 
            ans.insert(2);
            n = n/2; 
        } 

        // n must be odd at this point.  So we can skip  
        // one element (Note i = i +2) 
        for (int i = 3; i <= sqrt(n); i = i+2) 
        { 
            // While i divides n, print i and divide n 
            while (n%i == 0) 
            { 
                // printf("%d ", i); 
                ans.insert(i);
                n = n/i; 
            } 
        } 

        // This condition is to handle the case when n  
        // is a prime number greater than 2 
        if (n > 2) ans.insert(n);
            // printf ("%d ", n); 
        return ans;
    } 
    int distinctPrimeFactors(vector<int>& nums) {
        long long n = 1;
        set<long long> ans;
        for(int val: nums) {
            set<long long> t = primeFactors(val);
            ans.insert(t.begin(), t.end());
            // n *= val;
        }
        
        return ans.size();
    }
};