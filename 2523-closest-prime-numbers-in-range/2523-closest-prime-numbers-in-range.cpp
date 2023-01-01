class Solution {
public:
    vector<int> v;
    void collectPrime(int a, int b) {
        if (a <= 2) {
            a = 2;
            if (b >= 2) {
                // cout << a << " ";
                v.push_back(a);
                a++;
            }
        }

        // MAKING SURE THAT a IS ODD BEFORE WE BEGIN
        // THE LOOP
        if (a % 2 == 0)
            a++;

        // NOTE : WE TRAVERSE THROUGH ODD NUMBERS ONLY
        for (int i = a; i <= b; i = i + 2) {

            // flag variable to tell
            // if i is prime or not
            bool flag = 1;

            // WE TRAVERSE TILL SQUARE ROOT OF j only.
            // (LARGEST POSSIBLE VALUE OF A PRIME FACTOR)
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    flag = 0;
                    break;
                }
            }

            // flag = 1 means i is prime
            // and flag = 0 means i is not prime

            if (flag == 1){
              if(i==1)
                continue;
              else
                v.push_back(i);
            }
        }
    }
    
    vector<int> closestPrimes(int l, int r) {
        v.clear();
        collectPrime(l, r);
        int start = -1, end = -1;
        if(v.size() < 2) return {start, end};
        if(v.size() == 2) return v;
        
        int mini = INT_MAX;
        
        for(int i=1; i<v.size(); i++) {
            if(v[i] - v[i-1] < mini) {
                mini = v[i] - v[i-1];
                start = v[i-1], end = v[i];
            }
        }
        
        return {start, end};
    }
};