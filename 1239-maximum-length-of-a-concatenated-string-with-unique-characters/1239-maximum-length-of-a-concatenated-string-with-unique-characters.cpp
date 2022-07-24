class Solution {
public:
    int f(int ind, vector<string>& arr, string str, unordered_set<char> st) {
        if(ind >= arr.size()) return str.size(); 
        
        unordered_set<char> temp = st;
        for(char ch : arr[ind]) {
            if(temp.find(ch) != temp.end()) {
                return f(ind + 1, arr, str, st);
            } else {
                temp.insert(ch);
            }
        }
        
        int poss1 = f(ind+1, arr, str + arr[ind], temp);
        int poss2 = f(ind+1, arr, str, st);
        
        return max(poss1, poss2);
    }
    
    int maxLength(vector<string>& arr) {
        string str = "";
        unordered_set<char> st;
        return f(0, arr, str, st);
        // return str.size();
    }
};