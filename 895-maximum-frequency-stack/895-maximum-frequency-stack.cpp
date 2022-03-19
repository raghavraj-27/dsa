class FreqStack {
public:
    map<int, stack<int>> freqstack;
    map<int, int> freq;
    int maxFreq;
    FreqStack() {
        maxFreq = INT_MIN;
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        freqstack[freq[val]].push(val);
    }
    
    int pop() {
        int ans = freqstack[maxFreq].top();
        freq[ans]--;
        freqstack[maxFreq].pop();
        if(freqstack[maxFreq].empty()) {
            maxFreq--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */