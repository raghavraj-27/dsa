class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int x = 0;
        while(not st.empty() and st.top().first <= price) {
            x += st.top().second;
            st.pop();
            // x++;
        }
        st.push({price, x+1});
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */