class MyCalendar {
public:
    vector<pair<int, int>> v;
    MyCalendar() {
        
    }
    bool bs(int low, int high, int start, int end) {
        if(low > high) return true;
        
        int mid = (low + high) >> 1;
        int s = v[mid].first;
        int e = v[mid].second; 
        
        if(end <= s) return bs(low, mid-1, start, end);
        if(start >= e) return bs(mid+1, high, start, end);
        
        return false; 
        
        // if(start < s and end < e) return bs(low, mid-1, start, end);
        // if(start > s and end > e) return bs(mid+1, high, start, end);
        // if(start == s) return false;
        // if(start == e) {
        //     if(mid == v.size()-1) return true;
        //     else return bs(mid+1, high, start, end);
        // }
        // if(end == s) {
        //     if(mid == 0) return true;
        //     else return bs(low, mid-1, start, end);
        // }
        
        // if(start < s and end < e) return bs(low, mid-1, start, end);
        // if(start > s and end > e) return bs(mid+1, high, start, end);
        // if(start == s and end == e) return false;
        // if(start > s) return false;        
        // if(start < s) return false;
        // return true;
    }
    
    bool book(int start, int end) {
        if(v.size() == 0) {
            v.push_back({start, end});
            return true;
        } 
        
        sort(v.begin(), v.end());
        bool res = bs(0, v.size()-1, start, end);
        if(res) {
            v.push_back({start, end});
        }
        
        return res;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */