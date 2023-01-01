class Solution {
public:
    int findLen(int num) {
	int cnt = 0;
	while(num > 0) {
		cnt++;
		num /= 10;
	}
	return cnt;
}
int reverseDigits(int x) {     
    int neg = 1;
    if(x < 0) neg = -1;
    x = abs(x);

    int ans = 0;
    while(x > 0) {
        if(INT_MAX/10 < ans or (INT_MAX - x%10) < ans*10)
            return 0;
        ans = ans*10 + x%10;
        x = x / 10;
    }
    
    return ans*neg; 
}
    int minimumPartition(string s, int k) {
        int len = findLen(k);
        int i=0, cnt = 0;

        while(i < s.size()) {
            int pow = 1, j = i, currNum = 0;
            while(j < min(i+len, (int)s.size()) ) {
                currNum = currNum + (s[j] - '0') * pow;
                pow *= 10;
                j++;
            }

            int l = findLen(currNum);
            currNum = reverseDigits(currNum);
            while(currNum > 0 and currNum > k) {
                l--;
                currNum /= 10;
            }

            if(currNum == 0) {
                cnt = -1;
                break;
            }
            cnt++;
            i = i+l;
        }
        return cnt;
    }
};