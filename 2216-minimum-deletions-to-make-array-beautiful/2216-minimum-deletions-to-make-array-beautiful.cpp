class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int pre = -1, cnt = 0;
        for(int val : nums) {
            if(val == pre) {
                cnt++;
            } else {
                pre = pre < 0 ? val : -1;
            }
        }
        if((nums.size() - cnt)%2 != 0) {
            return cnt + 1;
        }
        return cnt;
    }
};