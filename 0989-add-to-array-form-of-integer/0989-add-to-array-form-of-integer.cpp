class Solution {
public:
    vector<int> add(vector<int>& num1, vector<int>& num2) {
        vector<int> ans;
        
        reverse(num1.begin(), num1.end());
        // reverse(num2.begin(), num2.end());
        
        int carry = 0, i = 0;
        while(i < num1.size() and i < num2.size()) {
            int sum = num1[i] + num2[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
            
            i++;
        }
        
        while(i < num1.size()) {
            int sum = num1[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
            
            i++;
        }
        
        while(i < num2.size()) {
            int sum = num2[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
            
            i++;
        }
        if(carry > 0) ans.push_back(carry);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> knum;
        while(k > 0) {
            knum.push_back(k % 10);
            k /= 10;
        }
        
        return add(num, knum);
    }
};