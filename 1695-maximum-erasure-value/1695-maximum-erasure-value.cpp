class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 1;
        unordered_set<int> st;
        st.insert(nums[0]);
        int max_sum = nums[0], sum = max_sum;
        
        while(right < nums.size()) {
            if(st.find(nums[right]) != st.end()) {
                while(left < right and st.find(nums[right]) != st.end()) {
                    sum -= nums[left];
                    st.erase(nums[left]);
                    left++;
                }
            }
            sum += nums[right];
            st.insert(nums[right]);
            max_sum = max(sum, max_sum);
            right++;
        }
        
        return max_sum;
    }
};