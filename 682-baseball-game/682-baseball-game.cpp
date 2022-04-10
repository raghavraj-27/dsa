class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> arr;
        for(int i=0; i<ops.size(); i++) {
            string ch = ops[i];
            if(ch=="C") {
                arr.pop_back();
            } else if(ch=="D") {
                arr.push_back(arr.back() * 2);
            } else if(ch=="+") {
                int n = arr.size();
                arr.push_back(arr[n-1] + arr[n-2]);
            } else {
                int val = stoi(ch);
                arr.push_back(val);
            }
        }
        
        return accumulate(arr.begin(), arr.end(), 0);
    }
};