class Solution {
public:
    map<int, string> mp;
    vector<int> v;
    Solution() {
        mp[1] = "I";        
        mp[5] = "V";
        mp[10] = "X";
        mp[50] = "L";
        mp[100] = "C";
        mp[500] = "D";
        mp[1000] = "M";
        mp[4] = "IV";
        mp[9] = "IX";
        mp[40] = "XL";
        mp[90] = "XC";
        mp[400] = "CD";
        mp[900] = "CM";

        v = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    }
    void convert(string& ans, int num) {
        if(num < 4) {
            for(int i=0; i<num; i++) {
                ans+="I";
            }
            return;
        }

        int ind = lower_bound(v.begin(), v.end(), num) - v.begin();
        if( ind == v.size() or v[ind] > num) {
            ind--;
        }

        ans += mp[v[ind]];
        convert(ans, num - v[ind]);
    }

    string intToRoman(int num) {
        string ans = "";
        convert(ans, num);
        return ans;
    }
};