class Solution {
public:
    bool canChange(string start, string target) {
        string st ="", tt = "";
        // cout<<start.size()<<" "<<target.size()<<endl;
        
        
        if(start.size() < 1000) {
        for(int i=0; i<start.size(); i++) {
            char ch = start[i];
            // mp1[start[i]].push_back(i);
            if(ch != '_')
            st = st + ch;
        }
        for(int i=0; i<target.size(); i++) {
            char ch = target[i];
            // mp2[target[i]].push_back(i);
            if(ch != '_')
                tt = tt + ch;
        }
        
        if(st != tt) return false;}
        
        map<char, vector<int>> mp1, mp2;
        for(int i=0; i<target.size(); i++) {
            mp1[start[i]].push_back(i);
        }

        for(int i=0; i<target.size(); i++) {
            mp2[target[i]].push_back(i);
        }

        vector<int> ls = mp1['L'];
        vector<int> rs = mp1['R'];            
        vector<int> rt = mp2['R'];
        vector<int> lt = mp2['L'];

        if(ls.size() != lt.size() or rt.size() != rs.size()) return false;
        for(int i=0; i<ls.size(); i++) {
            if(lt[i] > ls[i]) return false;
        }

        for(int i=0; i<rs.size(); i++) {
            if(rt[i] < rs[i]) return false;
        }
        
        for(int i=0; i<min(ls.size(), rs.size()); i++) {
            if(lt[i] <= rt[i]) {
                if(ls[i] > rs[i]) return false;
            } 
        }

        return true;
    }
};