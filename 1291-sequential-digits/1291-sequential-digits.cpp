class Solution {
public:
    vector<int> ans;
    int createNUM(int len) {
        int num=0, i, j;
        for(i=len-1, j=1; i>=0; i--, j++) {
            num += j*pow(10, i);
        }
        return num;
    }
    
    int createADD(int len) {
        string str = "";
        for(int i=0; i<len; i++) {
            str += "1";
        }
        return stoi(str);
    }
    
    Solution() {
        for(int len=2; len<=9; len++) {
            int num = createNUM(len);
            int add = createADD(len);
            while(num%10 != 0) {
                ans.push_back(num);
                num += add;
            }
        }
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v(lower_bound(begin(ans), end(ans), low), 
                     upper_bound(begin(ans), end(ans), high));
        return v;
    }
};