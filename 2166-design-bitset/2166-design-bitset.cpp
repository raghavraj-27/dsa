class Bitset {
public:
    int size;
    string val, lav;
    unordered_set<int> ones_val, ones_lav;
    Bitset(int s) {
        size = s;
        for(int i=0; i<size; i++) {
            val += "0";
            lav += "1";
            ones_lav.insert(i);
        }
    }
    
    void fix(int idx) {
        val[idx] = '1';
        ones_val.insert(idx);
        lav[idx] = '0';
        ones_lav.erase(idx);
    }
    
    void unfix(int idx) {
        val[idx] = '0';
        if(ones_val.find(idx) != ones_val.end()) 
            ones_val.erase(idx);
        lav[idx] = '1';
        ones_lav.insert(idx);
    }
    
    void flip() {
        /*
        for(int i=0; i<size; i++) {
            if(val[i] == '0') {
                val[i] = '1';
                ones.insert(i);
            }
            else {
                val[i] = '0';
                ones.erase(i);
            }
        }
        */
        swap(val, lav);
        swap(ones_val, ones_lav);
    }
    
    bool all() {
        return ones_val.size() == size;
    }
    
    bool one() {
        return ones_val.size() >= 1;
    }
    
    int count() {
        return ones_val.size();
    }
    
    string toString() {
        return val;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */