class Solution {
public:
    string decodeCiphertext(string et, int rows) {
        if(et.size() == 0) return "";
        int cols = et.size()/rows; 
        vector<vector<char>> arr(rows, vector<char> (cols)); 
        
        int p=0;
        int maxg = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                arr[i][j] = et[p];
                p++;
            }
        }
        
        string ot = ""; 
        for(int g=0; g<cols; g++) {
            for(int i=0, j=g; j<cols and i<rows; j++, i++) {
                ot += arr[i][j];
            }
        }
        int len = ot.size()-1;
        while(ot[len] == ' ') {
            len--;
        }
        return ot.substr(0, len+1);
    }
};