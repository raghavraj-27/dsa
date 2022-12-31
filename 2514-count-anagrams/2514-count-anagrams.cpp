class Solution {
public:
    int mod = 1000000007;
    vector<int> fact;
    int modulus(int a, int b) {
        return  ((long long)a%mod * b%mod ) % mod;
    }
    void storeFact() {
        int n = 100000;
        fact.resize(n+1);
        fact[0] = 1;
        for(int i=1; i<=n; i++) {
            fact[i] = modulus(fact[i-1], i);
        }
    }
    int power(int a, int p) {
        if(p == 0) return 1;
        if(p == 1) return a;
        
        // if(p & 1) return (a % mod * power(a, p-1) % mod);
        if(p & 1) return modulus(a, power(a, p-1));
        return power(modulus(a,a), p/2);
    }
    int ways(string word) {
        map<char, int> freq;

        for(char ch: word) freq[ch]++;
        int num = 1;
        for(auto p: freq) {
            num = modulus(num, fact[p.second]);
        }
        
        return modulus(fact[word.size()], power(num, mod-2));
    }
    int countAnagrams(string s) {
        storeFact();
        stringstream ss(s);
        string word;
        int ans = 1;
        while(ss >> word) {
            ans = modulus(ans, ways(word));
        }
        
        return ans;
    }
};