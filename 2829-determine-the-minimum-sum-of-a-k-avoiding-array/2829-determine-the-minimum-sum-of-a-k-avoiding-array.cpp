class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> st;
        int num = 1;
        while(st.size() < n) {
            if(num == k) {
                st.insert(num);
            }else if(num < k) {
                if(st.find(k-num) == st.end()) {
                    st.insert(num);
                }
            } else {
                st.insert(num);
            }
            num++;
        }
        
        int sum = 0;
        for(auto it: st) {
            // cout<<it<<" ";
            sum += it;
        }
        return sum;
    }
};