class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = 0;
        for(int val: derived) {
            sum = sum ^ val;
        }
        
        return sum == 0;
    }
};