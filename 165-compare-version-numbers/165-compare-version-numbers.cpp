class Solution {
public:
    int compareVersion(string a, string b) 
    {
        int i=0, j=0, numa=0, numb=0; 
        while(i<a.size() or j<b.size()) 
        {
            while(i<a.size() and a[i]!='.') {
                numa += (numa*10 + (a[i]-'0'));
                i++;
            }

            while(j<b.size() and b[j]!='.') {
                numb += (numb*10 + (b[j]-'0'));
                j++;
            }

            if(numa < numb) return -1;
            if(numa > numb) return 1;

            numa = 0, numb=0;
            i++, j++;
        }
        return 0;
    }
    /*
    int compareVersion(string version1, string version2) {
        vector<int> v1; 
        vector<int> v2; 
        
        int i=0;
        string v="";
        while(i < version1.size()) {
            if(version1[i] != '.') {
                v = v + version1[i];
            } else {
                v1.push_back(stoi(v)); 
                v = "";
            }
            i++;
        }
        
        v1.push_back(stoi(v));
        
        i=0;
        v="";
        while(i < version2.size()) {
            if(version2[i] != '.') {
                v = v + version2[i];
            } else {
                v2.push_back(stoi(v)); 
                v = "";
            }
            i++;
        }
        
        v2.push_back(stoi(v));
        
        i=0;
        int j=0; 
        while(i<v1.size() and j<v2.size()) {
            if(v1[i] > v2[j]) {
                return 1;
            } else if(v1[i] < v2[j]) {
                return -1;
            }
            i++; j++;
        }
        
        if(i>=v1.size() and j>=v2.size())
            return 0;
        
        while(i<v1.size()) {
            if(v1[i] > 0) {
                return 1;
            }
            i++;
        }
        
        while(j<v2.size()) {
            if(v2[j] > 0) {
                return -1;
            }
            j++;
        }
        
        return 0;
    }
    */
};