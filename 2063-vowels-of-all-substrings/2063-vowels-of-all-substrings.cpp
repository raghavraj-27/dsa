class Solution {
public:    bool isVowel(char ch) {
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
            return true;
        return false;

    }
    
    long long countVowels(string word) {
        long long int sum = 0; 
        long long int n = word.size(); 
        
        for(int i=0; i<n; i++) {
            if(isVowel(word[i])) {
                long long int len = n-i; 
                sum += (i*len) + len;
            }
        }
        
        return sum;
    }
};