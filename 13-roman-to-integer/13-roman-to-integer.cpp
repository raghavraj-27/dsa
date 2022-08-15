class Solution {
public:
    int romanToInt(string s) {
        int i=s.size()-1; 
        int ans = 0; 
        
        while(i >= 0) {
            if(i > 0) {
                if(s[i-1]=='I' and s[i]=='V') {
                    ans += 4; 
                    i = i - 2;
                } else if(s[i-1]=='I' and s[i]=='X') {
                    ans += 9;
                    i = i - 2;
                } else if(s[i-1]=='X' and s[i]=='L') {
                    ans += 40;
                    i = i - 2; 
                } else if(s[i-1]=='X' and s[i]=='C') {
                    ans += 90; 
                    i = i - 2;
                } else if(s[i-1]=='C' and s[i]=='D') {
                    ans += 400;
                    i = i - 2;
                } else if(s[i-1]=='C' and s[i]=='M') {
                    ans += 900; 
                    i = i - 2;
                } else if(s[i]=='I') {
                    ans++; 
                    i--;
                } else if(s[i]=='V') {
                    ans += 5;
                    i--;
                } else if(s[i]=='X') {
                    ans += 10; 
                    i--;
                } else if(s[i]=='L') {
                    ans += 50; 
                    i--;
                } else if(s[i]=='C') {
                    ans += 100; 
                    i--;
                } else if(s[i]=='D') {
                    ans += 500;
                    i--;
                } else if(s[i]=='M') {
                    ans += 1000;
                    i--;
                }
            }
            else if(s[i]=='I') {
                ans++; 
                i--;
            } else if(s[i]=='V') {
                ans += 5;
                i--;
            } else if(s[i]=='X') {
                ans += 10; 
                i--;
            } else if(s[i]=='L') {
                ans += 50; 
                i--;
            } else if(s[i]=='C') {
                ans += 100; 
                i--;
            } else if(s[i]=='D') {
                ans += 500;
                i--;
            } else if(s[i]=='M') {
                ans += 1000;
                i--;
            }
        }
        
        return ans;
    }
};