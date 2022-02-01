class Solution {
public:
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        long long p = 1, hash = 0;
        for(int i=1; i<k; i++) {
            p = (p * power) % mod;
        }
        
        string str(s.rbegin(), s.rend());
        vector<int> myHashValue(s.size());
        for(int i=0; i<str.size(); i++) {
            if(i < k) {
                hash = (hash*power + (str[i] - 'a' + 1))%mod;
            }
            
            if(i == k-1) {
                myHashValue[i] = hash;
            } else if(i >= k) {
                hash = (((hash - (str[i-k] - 'a' + 1)*p%mod)*power)%mod + (str[i] - 'a' + 1)) % mod;
                
                if(hash < 0)
                    hash += mod;
                myHashValue[i] = hash;
            }
        }
        
        reverse(begin(myHashValue), end(myHashValue));
        for(int i=0; i<s.size(); i++) {
            if(hashValue == myHashValue[i]) 
                return s.substr(i, k);
        }
        return "";
    }
};