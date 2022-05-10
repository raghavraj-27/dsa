class Solution {
public:
    // Gap Strategy
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int j=0; j<n; j++) {
            nums1[m+j] = nums2[j];
        }
        
        int gap = ceil((m + n) / 2.0);
        
        // if((m+n) % 2 == 1)
        //     gap++; 
        
        for(int g=gap; g>0; )
        {
            int i=0, j=g; 
            while(j<nums1.size())
            {
                if(nums1[i] > nums1[j])
                    swap(nums1[i], nums1[j]);
                i++; j++;
            }
            
            if(g%2 == 1 and g!=1)
                g = g/2 + 1;
            else
                g = g/2;
        }
    }
};