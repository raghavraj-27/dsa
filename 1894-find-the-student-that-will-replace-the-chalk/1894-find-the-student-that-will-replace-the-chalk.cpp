class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = accumulate(chalk.begin(), chalk.end(), 0l);
        k = k % sum;
        
        for(int i=0; i<chalk.size(); i++) {
            if(chalk[i] > k) {
                return i;
            } else {
                k = k - chalk[i];
            }
        }
        
        return 0;
    }
};


// i use chalk[i] amount of chalk
