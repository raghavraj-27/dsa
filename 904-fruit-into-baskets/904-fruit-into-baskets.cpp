class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int i = 0;
        int ans = 0, cnt = 0;
        while(i < fruits.size()) {
            
            freq[fruits[i]]++;
            cnt++;
            if(freq.size() > 2) {
                int fruit = fruits[i-1];
                int ptr = i-1;
                int c = 0;
                while(ptr>=0 and fruits[ptr] == fruit) {
                    // freq
                    c++;
                    ptr--;
                }
                cnt = 1 + c;
                freq.erase(fruits[ptr]);
            }
            ans = max(ans, cnt);
            i++;
        }\
        return ans;
    }
};