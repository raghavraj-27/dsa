class MedianFinder {
public:
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // if(maxHeap.size()==0 and minHeap.size()==0)
        //     maxHeap.push(num);
        // else if(maxHeap.size() == minHeap.size())
        // {
        //     if(num < maxHeap.top())
        //         maxHeap.push(num); 
        //     else
        //     {
        //         maxHeap.push(minHeap.top()); 
        //         minHeap.pop(); 
        //         minHeap.push(num);
        //     }
        // }
        // else 
        // {
        //     if(minHeap.size() == 0)
        //     {
        //         if(num < maxHeap.top())
        //         {
        //             minHeap.push(maxHeap.top()); 
        //             maxHeap.pop(); 
        //             maxHeap.push(num);
        //         }
        //         else
        //             minHeap.push(num);
        //     }
        //     else if(num >= minHeap.top())
        //         minHeap.push(num);
        //     else
        //     {
        //         if(num < maxHeap.top())
        //         {
        //             minHeap.push(maxHeap.top()); 
        //             maxHeap.pop(); 
        //             maxHeap.push(num);
        //         }
        //         else
        //             minHeap.push(num);
        //     }
        // }
        
        maxHeap.push(num); 
        minHeap.push(maxHeap.top()); 
        maxHeap.pop(); 
        if(minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top()); 
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */