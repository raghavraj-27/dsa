class Solution {
public:
    int maxArea(vector<int> h) {
        stack<int> st; 
        int n = h.size(); 
        int area = 0;
        
        for(int i=0; i<=n; i++) {
            while(not st.empty() and (i==n or h[st.top()] >= h[i])) {
                int height = h[st.top()];
                st.pop(); 
                
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                
                area = max(area, height * width);
            }
            st.push(i);
        }
        
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v; 
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i=0; i<n; i++) {
            v.push_back(matrix[0][i] - '0');
        }
        int ans = maxArea(v);
        
        for(int i=1; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] - '0') {
                    v[j] += 1;
                } else {
                    v[j] = 0;
                }
            }
            ans = max(ans, maxArea(v));
        }
        
        return ans;
    }
};