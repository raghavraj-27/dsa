class Solution {
public:
    
    int minDeletions(string s) {
        map<char, int> freq;
        for(char ch : s) {
            freq[ch]++;
        }
        
        vector<int> arr;
        for(auto p : freq) {
            arr.push_back(p.second);
        }
        
        sort(arr.rbegin(), arr.rend());
        set<int> prev;
        // map<int, int> mp;
        // for(int a : arr) {
        //     mp[a]++;
        // }
        
        int ans = 0;
        for(int i=0; i<arr.size(); i++) {
            int num = arr[i];
            while(num > 0 and prev.find(num) != prev.end()) {
                ans++;
                num--;
            }
            if(num > 0) {
                prev.insert(num);
            }
        }
        
        return ans;
    }
};
// // abbbccdeeefffggghh
// ans = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1
// // 1,3,2,1,3,3,3,2
//          0 0 0 0 0
// 1,3,2
// mp[1] = 2
// mp[2] = 2
// mp[3] = 4