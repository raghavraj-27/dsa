class Solution {
public:
    void merge(int low, int mid, int high, vector<int>& nums, vector<int>& temp) {
        int i = low, j = mid, k = low;
        
        while(i <= mid-1 and j <= high) {
            if(nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while(i <= mid-1) {
            temp[k++] = nums[i++];
        }
        
        while(j <= high) {
            temp[k++] = nums[j++];
        }
        
        for(int i=low; i<=high; i++) {
            nums[i] = temp[i];
        }
    }
    
    void mergeSort(int low, int high, vector<int>& nums, vector<int>& temp) {
        if(low >= high) return;
        
        int mid = (low + high) / 2;
        
        mergeSort(low, mid, nums, temp);
        mergeSort(mid+1, high, nums, temp);
        
        merge(low, mid+1, high, nums, temp);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        
        mergeSort(0, n-1, nums, temp);
        return nums;
    }
};