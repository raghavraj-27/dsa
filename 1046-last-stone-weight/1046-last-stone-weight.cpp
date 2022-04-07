class Solution {
public:
    int lastStoneWeight(vector<int>& stone) {
        while(stone.size() > 1) {
            sort(stone.begin(), stone.end());
            int n = stone.size();
            if(stone[n-1] == stone[n-2]) {
                stone.pop_back(); 
                stone.pop_back();
            } else {
                int val = stone[n-1] - stone[n-2];
                stone.pop_back(); 
                stone.pop_back();
                stone.push_back(val);
            }
        }
        if(stone.size() == 1) return stone[0];
        return 0;
    }
};