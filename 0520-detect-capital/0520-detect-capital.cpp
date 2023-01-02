class Solution {
public:
    bool allBig(string s) {
        for(int i=1; i<s.size(); i++) {
            if(not ('A' <= s[i] and s[i] <= 'Z')) {
                return false;
            }
        }
        return true;
    }
    bool allSmall(string s) {
        for(int i=1; i<s.size(); i++) {
            if(not ('a' <= s[i] and s[i] <= 'z')) {
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string s) {
        if('A' <= s[0] and s[0] <= 'Z') {
            return allBig(s) or allSmall(s);
            // if(s.size() == 1) return true;
            // else return false;
        } 
        // else {
            return allSmall(s);
        // }
        // bool flagCap = false, flagSm = false;
        
        // if(s.size() > 1) {
        //     if('a' <= s[1] and s[1] <= 'z') {
        //         for(int i=2; i<s.size(); i++) {
        //             if(not ('a' <= s[i] and s[i] <= 'z')) {
        //                 return false;
        //             }
        //         }
        //         return true;
        //     } else {
        //         for(int i=2; i<s.size(); i++) {
        //             if(not ('A' <= s[i] and s[i] <= 'Z')) {
        //                 return false;
        //             }
        //         }
        //         return true;
        //     }
        // }
        // // for(int i=1; i<s.size(); i++) {
        // //     if(s[i])
        // // }
        // return true;
    }
};