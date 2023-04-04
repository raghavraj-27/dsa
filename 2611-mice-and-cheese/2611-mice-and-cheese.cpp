class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<pair<int, int>> maxHeap;
        int n = reward1.size();
        
        int total = accumulate(reward2.begin(), reward2.end(), 0);
        
        for(int i=0; i<n; i++) {
            maxHeap.push(make_pair(reward1[i] - reward2[i], i));
        }
        
        while(k--) {
            total += maxHeap.top().first;
            maxHeap.pop();
        }
        
        return total;
    }
};