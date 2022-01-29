class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); 
        vector<int> left(n), right(n); 
        stack<int> st1, st2; 
        
        for(int i=0; i<n; i++) {
            if(st1.empty()) {
                left[i] = 0; 
                st1.push(i); 
            }
            else {
                while(!st1.empty() and heights[i] <= heights[st1.top()]) {
                    st1.pop(); 
                }
                
                if(st1.empty()) {
                    left[i] = 0; 
                    st1.push(i); 
                } else {
                    left[i] = st1.top() + 1; 
                    st1.push(i);
                }
            }
        }
         
        
        for(int i=n-1; i>=0; i--) {
            if(st2.empty()) {
                right[i] = n-1; 
                st2.push(i); 
            } else {
                while(!st2.empty() and heights[i] <= heights[st2.top()]) {
                    st2.pop(); 
                }
                
                if(st2.empty()) {
                    right[i] = n-1; 
                    st2.push(i); 
                } else {
                    right[i] = st2.top() - 1; 
                    st2.push(i);
                }
            }
        }
        
        int maxarea = 0; 
        for(int i=0; i<n; i++) {
            int currarea = (right[i] - left[i] + 1) * heights[i]; 
            maxarea = max(maxarea, currarea); 
        }
        
        return maxarea;
    }
};