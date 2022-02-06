class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) return 0;
        vector<int> digits;
        bool negetive = num<0;
        if(negetive) num = -1*num;
        long long n = num; 
        while(n > 0) {
            digits.push_back(n % 10);
            n = n / 10;
        }
        
        reverse(digits.begin(), digits.end());
        
        long long ans = 0;
        if(negetive) {
            sort(digits.rbegin(), digits.rend());
            for(long long i=0, len=digits.size()-1; i<digits.size(); i++, len--) {
                ans += digits[i]*pow(10l, len);
            }
            if(negetive) ans *= (long long)-1;
        } else {
            sort(digits.begin(), digits.end());
            int p=0; while(digits[p] == 0) p++;
            reverse(digits.begin(), digits.begin()+p+1);
            for(long long i=0, len=digits.size()-1; i<digits.size(); i++, len--) {
                ans += digits[i]*pow(10l, len);
            }
        }
        
        return ans;
    }
};