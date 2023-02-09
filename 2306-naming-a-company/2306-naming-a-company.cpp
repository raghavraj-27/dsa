#define ll long long
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        ll ans = 0;
        int n = ideas.size();
        
        unordered_set<string> mp[26];
        
        for(string s: ideas) {
            string suffix = s.substr(1);
            mp[s[0] - 'a'].insert(suffix);
        }
        
        for(int i=0; i<26; i++) {
            for(int j=i+1; j<26; j++) {
                ll cnt1 = 0ll, cnt2 = 0ll;
                for(auto& it: mp[i]) {
                    if(not mp[j].count(it)) cnt1++;
                }
                for(auto& it: mp[j]) {
                    if(not mp[i].count(it)) cnt2++;;
                }
                
                ans += cnt1 * cnt2;
            }
        }
        // for(auto it: mp) {
        //     cout<<it.first<<"-";
        //     for(auto itr: it.second) {
        //         cout<<itr<<", ";
        //     }
        //     cout<<endl;
        // }
        
        return ans*2ll;
    }
};