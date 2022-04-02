class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size() - 1;
        
        while(start <= end) 
        {
            char temp = s.at(start); 
            s.at(start) = s.at(end); 
            s.at(end) = temp; 
            
            start++; end--;
        }
        
        //return s;
    }
};