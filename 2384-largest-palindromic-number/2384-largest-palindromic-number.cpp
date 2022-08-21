class Solution {
public:
    string largestPalindromic(string num) {
        set<char, greater<int>> s(num.begin(), num.end());
        map<char, int> mp;
         for(char ch: num) {
            mp[ch]++;
        }
        if(mp.size() == 1) {
            if(mp.find('0') != mp.end()) {
                string st = "";
                st += *s.begin();
                return st;
            } else {
                return num;
            }
        }
        if(mp.size() == 2 and mp.find('0') != mp.end() and mp.rbegin()->second == 1) {
            string st = "";
            st += *s.begin();
            cout<<st<<endl;
            return st;
        }
        
       
        
        string s1 = "", s2 = "";
        char mid;
        bool flag = true;
        for(auto it: s) {
            if(mp[it]&1 and flag) {
                mid = it;
                mp[it]--;
                
                if(mp[it] != 0) {
                    for(int i=0; i<mp[it]/2; i++) {
                        s1.push_back(it);
                        s2.push_back(it);
                    }
                }
                flag = false;
            } else {
                for(int i=0; i<mp[it]/2; i++) {
                    s1.push_back(it);
                    s2.push_back(it);
                }
            }
        }
        
        reverse(s2.begin(), s2.end());
        if(flag == false) {
            return s1 + mid + s2;
        }
        
        return s1 + s2;
    }
};