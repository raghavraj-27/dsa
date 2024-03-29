class Solution {
public:
    vector<int> f(int r) {
        vector<int> v(r, 1);
        
        int N = r-1, val = 1;
        for(int i=0; i<r-2; i++) {
            val *= (N-i);
            val /= (i+1);
            
            v[i+1] = val;
        }
        
        return v;
    }
    
    
    
    vector<vector<int>> generate(int n) {
        // n = row
        //     => nth row will have n elements
        //     if n=1 ,      1                  0C0     
        //     if n=2,      1 1               0C0 0C0   
        //     if n=3,     1 2 1            2C0 2C1 2C2
        //     if n=4,    1 3 3 1         3C0 3C1 3C2 3C3
        vector<vector<int>> ans;
        if(n >= 1) {
            ans.push_back({1});
        }
        if(n >= 2) {
            ans.push_back({1, 1});
        }
        
        for(int i=3; i<=n; i++) {
            ans.push_back(f(i));
        }
        
        return ans;
    }
};