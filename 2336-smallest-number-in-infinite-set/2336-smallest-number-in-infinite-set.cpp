class SmallestInfiniteSet {
public:
    unordered_set<int> store;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++) {
            store.insert(i);
            minHeap.push(i);
        }
    }
    
    int popSmallest() {
        int ans = minHeap.top();
        minHeap.pop();
        store.erase(ans);
        return ans;
    }
    
    void addBack(int num) {
        if(store.find(num) != store.end()) return;
        store.insert(num);
        minHeap.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */