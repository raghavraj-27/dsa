class Solution {
public:
    int sumDigits(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num%10;
            num = num / 10;
        }
        return sum;
    }
    int addDigits(int num) {
        int ans = sumDigits(num);
        num = ans;
        while(num > 9) {
            num = sumDigits(num);
        }
        return num;
    }
};