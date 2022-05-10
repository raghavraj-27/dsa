class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++) {
            nums1[m + i] = nums2[i];
        }
        
        int gap = ceil((m+n) / 2.0);
        
        for(int g=gap; g>0; ) {
            int i = 0, j = g;
            while(j < nums1.size()) {
                if(nums1[i] > nums1[j]) {
                    swap(nums1[i], nums1[j]);
                }
                i++; j++;
                
            }
            
            if(g != 1 and g%2 == 1) g = g/2 + 1;
            else g = g / 2;
        }
    }
};