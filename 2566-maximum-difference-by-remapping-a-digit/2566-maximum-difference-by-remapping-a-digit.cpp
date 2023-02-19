class Solution {
public:
    int convertToNumber(vector<int>& v) {
        int num = 0;
        for(int i=v.size()-1; i>=0; i--) {
            num += v[i] * pow(10, v.size()-1-i);
        }
        return num;
    }
    int minMaxDifference(int num) {
        vector<int> v;
        int n = num;
        
        while(n > 0) {
            v.push_back(n% 10);
            n /= 10;
        }
        
        reverse(v.begin(), v.end());
        
        vector<int> min_v(v.begin(), v.end());
        vector<int> max_v(v.begin(), v.end());
        
        int num_to_swap_for_min = v[0];
        int num_to_swap_for_max = 9;
        int i = 0;
        while(i < v.size() and v[i] == 9) i++;
        if(i < v.size()) {
            num_to_swap_for_max = v[i];
        }
        
        
        for(int i=0; i<v.size(); i++) {
            if(min_v[i] == num_to_swap_for_min) {
                min_v[i] = 0;
            }
            if(max_v[i] == num_to_swap_for_max) {
                max_v[i] = 9;
            }
        }
        
        int num1 = convertToNumber(min_v);
        int num2 = convertToNumber(max_v);
        
        return num2 - num1;
    }
};