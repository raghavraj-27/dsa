class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<nums2.size(); i++) {
            nums1[m+i] = nums2[i];
        }
        // nums1.append(nums2);
        
        int gap = ceil((m + n) / 2.0);
        int g = gap;
        while(g > 0) {
            int i = 0, j = g;
            while(j < nums1.size()) {
                if(nums1[i] > nums1[j]) {
                    swap(nums1[i], nums1[j]);
                }
                i++; j++;
            }
            
            if(g%2 != 0 and g != 1) g = g/2 + 1;
            else g = g / 2;
        }
    }
};