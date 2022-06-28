class Solution {
public:
     int myAtoi(string s) {
        int i=0; 
        
        while(i < s.size() and s[i] == ' ') {
            i++;
        }
        
        if(i >= s.size()) {
            return 0; 
        }
        
        int sign = 1;
        if(s[i] == '+' or s[i] == '-') {
            sign = (s[i]=='+') ? 1 : -1;
            i++;
        }
        
        int base = 0;
        for(; i<s.size() and s[i]>='0' and s[i]<='9'; i++) {
            if(base > INT_MAX/10 or (base == INT_MAX/10 and (s[i]-'0') > INT_MAX%10)) {
                if(sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            base = base * 10 + (s[i] - '0');
        }
        
        return base*sign;
    }
};