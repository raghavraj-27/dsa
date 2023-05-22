class Solution {
public:
    bool isPunishmentNumber(string num, int target) {
        if(num == "" and target == 0) return true;
        if(target < 0) return false;
        
        for(int i=0; i<num.size(); i++) {
            string left = num.substr(0, i+1);
            string right = num.substr(i+1);
            
            int numLeft = stoi(left);
            
            if(isPunishmentNumber(right, target - numLeft)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        
        for(int i=1; i<=n; i++) {
            int square = i * i;
            
            if(isPunishmentNumber(to_string(square), i)) {
                sum += square;
            }
        }
        
        return sum;
    }
};