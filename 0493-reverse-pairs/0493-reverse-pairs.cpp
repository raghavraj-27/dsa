class Solution {
public:
    int cnt;
    void merge(int left, int mid, int right, vector<int>& nums, vector<int>& temp) {
        int i=left, j=mid, k=left;
        
        for(i=left; i<=mid-1; i++) {
            while(j <= right and nums[i] > 2ll * nums[j]) {
                j++;
            }
            cnt += j-mid;
        }
        
        i = left; j = mid; k = left;
        while(i <= mid-1 and j<=right) {
            if(nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while(i <= mid-1) {
            temp[k++] = nums[i++];
        }
        while(j <= right) {
            temp[k++] = nums[j++];
        }
        
        for(int i=left; i<=right; i++) {
            nums[i] = temp[i];
        }
    }
    
    void mergeSort(int left, int right, vector<int>& nums, vector<int>& temp) {
        if(left >= right) return;
        int mid = (left + right) >> 1;
        
        mergeSort(left, mid, nums, temp);
        mergeSort(mid+1, right, nums, temp);
        
        merge(left, mid+1, right, nums, temp);
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        cnt = 0;
        
        mergeSort(0, n-1, nums, temp);
        
        return cnt;
    }
};