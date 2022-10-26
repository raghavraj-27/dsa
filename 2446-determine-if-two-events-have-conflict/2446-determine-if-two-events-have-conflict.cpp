class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int stMin1 = stoi(event1[0])*60 + stoi(event1[0].substr(3));
        int etMin1 = stoi(event1[1])*60 + stoi(event1[1].substr(3));
        
        int stMin2 = stoi(event2[0])*60 + stoi(event2[0].substr(3));
        int etMin2 = stoi(event2[1])*60 + stoi(event2[1].substr(3));
        
        if(stMin1 <= stMin2 and stMin2 <= etMin1) return true;
        if(stMin2 <= stMin1 and stMin1 <= etMin2) return true;
        return false;
    }
};