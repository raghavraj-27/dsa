class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k > 0) {
            int n = num.size(); 
            int i=0;
            while(i<n-1 and num[i]<=num[i+1]) i++;
            num.erase(i, 1);
            k--;
        }
        
        while(num.front() == '0') {
            num.erase(0,1);
        }
        
        return num=="" ? "0" : num;
    }
};